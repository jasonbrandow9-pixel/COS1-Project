#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <vector>

enum class HealthState
{
    Susceptible,
    Infected,
    Recovered
};

struct VirusProfile
{
    std::string name;
    std::string description;
    int contactsPerDay;
    double transmissionChance;
    int recoveryDays;
};

struct Person
{
    HealthState state = HealthState::Susceptible;
    int infectionAge = 0;
};

struct SimulationSummary
{
    int daysRun = 0;
    int peakInfected = 0;
    int finalInfected = 0;
    int finalRecovered = 0;
    int totalPopulation = 0;
};

namespace
{
    constexpr int kWidth = 30;
    constexpr int kHeight = 14;
    constexpr int kPopulation = kWidth * kHeight;

    const std::string kGreen = "\x1B[32m";
    const std::string kYellow = "\x1B[33m";
    const std::string kCyan = "\x1B[36m";
    const std::string kRed = "\x1B[31m";
    const std::string kReset = "\x1B[0m";

    std::vector<VirusProfile> createProfiles()
    {
        return {
            {"Common-cold style", "Lower-spread illustrative preset with quicker recovery.", 2, 0.18, 5},
            {"Seasonal-flu style", "Moderate illustrative preset with a longer infectious window.", 3, 0.28, 7},
            {"High-transmission style", "Higher-spread illustrative preset for comparing outbreak speed.", 4, 0.42, 9}
        };
    }

    void printBanner()
    {
        std::cout << kCyan
                  << "\n  ================================================================\n"
                  << "              VIRUS SPREAD LAB\n"
                  << "     Explore transmission, recovery, and outbreak curves\n"
                  << "  ================================================================\n"
                  << kReset;
    }

    void pauseForUser()
    {
        std::cout << "\nPress Enter to continue...";
        std::string ignored;
        std::getline(std::cin, ignored);
    }

    int readMenuChoice(int minimum, int maximum)
    {
        int choice = 0;
        while (true)
        {
            std::cout << "Choose an option (" << minimum << "-" << maximum << "): ";
            if (std::cin >> choice && choice >= minimum && choice <= maximum)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return choice;
            }

            std::cout << kRed << "Please enter a valid number.\n" << kReset;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    void printProfile(const VirusProfile& profile, int number)
    {
        std::cout << "  " << number << ". " << profile.name << "\n"
                  << "     " << profile.description << "\n"
                  << "     Contacts/day: " << profile.contactsPerDay
                  << " | Transmission chance: " << std::fixed << std::setprecision(0)
                  << profile.transmissionChance * 100 << "%"
                  << " | Recovery: " << profile.recoveryDays << " days\n";
    }

    std::size_t countState(const std::vector<Person>& people, HealthState state)
    {
        return static_cast<std::size_t>(std::count_if(people.begin(), people.end(),
            [state](const Person& person) { return person.state == state; }));
    }

    void printGrid(const std::vector<Person>& people)
    {
        std::cout << "\n" << kYellow << "LIVE GRID" << kReset << "\n";
        std::cout << "  " << kGreen << "." << kReset << " susceptible   "
                  << kRed << "#" << kReset << " infected   "
                  << kCyan << "+" << kReset << " recovered\n\n";

        for (int row = 0; row < kHeight; ++row)
        {
            std::cout << "  ";
            for (int column = 0; column < kWidth; ++column)
            {
                const Person& person = people[row * kWidth + column];
                if (person.state == HealthState::Infected)
                {
                    std::cout << kRed << '#' << kReset;
                }
                else if (person.state == HealthState::Recovered)
                {
                    std::cout << kCyan << '+' << kReset;
                }
                else
                {
                    std::cout << kGreen << '.' << kReset;
                }
            }
            std::cout << '\n';
        }
    }

    int neighborIndex(int index, int direction)
    {
        const int row = index / kWidth;
        const int column = index % kWidth;
        const int nextRow = row + (direction == 0 ? -1 : direction == 1 ? 1 : 0);
        const int nextColumn = column + (direction == 2 ? -1 : direction == 3 ? 1 : 0);

        if (nextRow < 0 || nextRow >= kHeight || nextColumn < 0 || nextColumn >= kWidth)
        {
            return -1;
        }
        return nextRow * kWidth + nextColumn;
    }

    SimulationSummary runSimulation(const VirusProfile& profile, int days, int initialInfected,
                                    unsigned int seed, bool showDailyReport)
    {
        std::mt19937 generator(seed);
        std::uniform_int_distribution<int> startDistribution(0, kPopulation - 1);
        std::uniform_int_distribution<int> directionDistribution(0, 3);
        std::uniform_real_distribution<double> chanceDistribution(0.0, 1.0);
        std::vector<Person> people(kPopulation);

        int seeded = 0;
        while (seeded < initialInfected)
        {
            const int index = startDistribution(generator);
            if (people[index].state == HealthState::Susceptible)
            {
                people[index].state = HealthState::Infected;
                ++seeded;
            }
        }

        SimulationSummary summary;
        summary.totalPopulation = kPopulation;
        summary.peakInfected = initialInfected;

        if (showDailyReport)
        {
            std::cout << "\n" << kYellow << "OUTBREAK REPORT: " << profile.name << kReset << "\n";
            std::cout << "This is a simplified educational model, not a medical forecast.\n\n";
            printGrid(people);
            std::cout << "\nDay  Susceptible  Infected  Recovered  New infections  Spread factor\n";
            std::cout << "---  -----------  --------  ---------  ---------------  -------------\n";
        }

        for (int day = 1; day <= days; ++day)
        {
            const int infectedBefore = static_cast<int>(countState(people, HealthState::Infected));
            if (infectedBefore == 0)
            {
                break;
            }

            std::vector<Person> next = people;
            int newInfections = 0;
            for (int index = 0; index < kPopulation; ++index)
            {
                if (people[index].state != HealthState::Infected)
                {
                    continue;
                }

                for (int contact = 0; contact < profile.contactsPerDay; ++contact)
                {
                    const int neighbor = neighborIndex(index, directionDistribution(generator));
                    if (neighbor >= 0 && people[neighbor].state == HealthState::Susceptible &&
                        next[neighbor].state == HealthState::Susceptible &&
                        chanceDistribution(generator) < profile.transmissionChance)
                    {
                        next[neighbor].state = HealthState::Infected;
                        next[neighbor].infectionAge = 0;
                        ++newInfections;
                    }
                }

                next[index].infectionAge = people[index].infectionAge + 1;
                if (next[index].infectionAge >= profile.recoveryDays)
                {
                    next[index].state = HealthState::Recovered;
                }
            }

            people = next;
            const int infectedAfter = static_cast<int>(countState(people, HealthState::Infected));
            const int recovered = static_cast<int>(countState(people, HealthState::Recovered));
            summary.peakInfected = std::max(summary.peakInfected, infectedAfter);
            summary.daysRun = day;

            if (showDailyReport)
            {
                const double spreadFactor = infectedBefore == 0 ? 0.0 :
                    static_cast<double>(newInfections) / infectedBefore;
                std::cout << std::setw(3) << day << "  "
                          << std::setw(11) << kPopulation - infectedAfter - recovered << "  "
                          << std::setw(8) << infectedAfter << "  "
                          << std::setw(9) << recovered << "  "
                          << std::setw(15) << newInfections << "  "
                          << std::setw(13) << std::fixed << std::setprecision(2) << spreadFactor << '\n';

                if (day % 5 == 0 || infectedAfter == 0 || day == days)
                {
                    printGrid(people);
                }
            }
        }

        summary.finalInfected = static_cast<int>(countState(people, HealthState::Infected));
        summary.finalRecovered = static_cast<int>(countState(people, HealthState::Recovered));
        return summary;
    }

    void runInteractiveSimulation(const std::vector<VirusProfile>& profiles)
    {
        std::cout << "\n" << kYellow << "CHOOSE AN ILLUSTRATIVE PROFILE" << kReset << "\n";
        for (std::size_t i = 0; i < profiles.size(); ++i)
        {
            printProfile(profiles[i], static_cast<int>(i + 1));
        }

        const int profileChoice = readMenuChoice(1, static_cast<int>(profiles.size()));
        std::cout << "\nHow many days should the model run?\n";
        const int days = readMenuChoice(1, 60);
        std::cout << "\nHow many initial infected people?\n";
        const int initial = readMenuChoice(1, 10);

        runSimulation(profiles[profileChoice - 1], days, initial, std::random_device{}(), true);
        pauseForUser();
    }

    void compareProfiles(const std::vector<VirusProfile>& profiles)
    {
        std::cout << "\n" << kYellow << "PROFILE COMPARISON" << kReset << "\n";
        std::cout << "Each profile uses the same population size, starting cases, and time window.\n";
        std::cout << "The settings are illustrative and intentionally not clinical estimates.\n\n";

        const int days = 30;
        const int initial = 3;
        std::cout << "Profile                         Peak infected  Recovered by day 30  Days simulated\n";
        std::cout << "------------------------------  -------------  --------------------  --------------\n";
        for (std::size_t i = 0; i < profiles.size(); ++i)
        {
            const SimulationSummary result = runSimulation(profiles[i], days, initial,
                                                            static_cast<unsigned int>(900 + i), false);
            std::cout << std::left << std::setw(32) << profiles[i].name
                      << std::right << std::setw(13) << result.peakInfected
                      << std::setw(22) << result.finalRecovered
                      << std::setw(16) << result.daysRun << '\n';
        }
        pauseForUser();
    }

    void explainModel()
    {
        std::cout << "\n" << kYellow << "HOW THE MODEL WORKS" << kReset << "\n"
                  << "- Each dot is susceptible, each # is infected, and each + has recovered.\n"
                  << "- Infected people make a few random nearby contacts each simulated day.\n"
                  << "- A contact can transmit according to the selected illustrative chance.\n"
                  << "- After the selected recovery window, infected people move to recovered.\n"
                  << "- Spread factor is new infections divided by infected people at the start\n"
                  << "  of that day; it helps compare outbreak momentum over time.\n\n"
                  << kRed << "Important: this is a classroom visualization, not medical advice,\n"
                  << "a prediction, or a substitute for public-health data.\n" << kReset;
        pauseForUser();
    }
}

int main()
{
    const std::vector<VirusProfile> profiles = createProfiles();
    printBanner();

    bool running = true;
    while (running)
    {
        std::cout << "\n" << kCyan << "MAIN MENU" << kReset << "\n"
                  << "  1. Run an outbreak simulation\n"
                  << "  2. Compare illustrative profiles\n"
                  << "  3. Learn how the model works\n"
                  << "  4. Exit\n";

        switch (readMenuChoice(1, 4))
        {
        case 1:
            runInteractiveSimulation(profiles);
            break;
        case 2:
            compareProfiles(profiles);
            break;
        case 3:
            explainModel();
            break;
        case 4:
            running = false;
            break;
        }
    }

    std::cout << "\nKeep learning, keep testing, and keep questioning the model.\n";
    return 0;
}
