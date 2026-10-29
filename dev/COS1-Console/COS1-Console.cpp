#include "Person.h"
#include "Simulation.h"
#include "VirusProfile.h"

#include <iomanip>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <vector>

namespace
{
    const std::string kGreen = "\x1B[32m";
    const std::string kYellow = "\x1B[33m";
    const std::string kCyan = "\x1B[36m";
    const std::string kRed = "\x1B[31m";
    const std::string kReset = "\x1B[0m";

    std::vector<VirusProfile> createProfiles()
    {
        return {
            VirusProfile("Common-cold style",
                         "Lower-spread illustrative preset with quicker recovery.",
                         2, 0.18, 5),
            VirusProfile("Seasonal-flu style",
                         "Moderate illustrative preset with a longer infectious window.",
                         3, 0.28, 7),
            VirusProfile("High-transmission style",
                         "Higher-spread illustrative preset for comparing outbreak speed.",
                         4, 0.42, 9)
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
        std::cout << "  " << number << ". " << profile.getName() << "\n"
                  << "     " << profile.getDescription() << "\n"
                  << "     Contacts/day: " << profile.getContactsPerDay()
                  << " | Transmission chance: " << std::fixed << std::setprecision(0)
                  << profile.getTransmissionChance() * 100 << "%"
                  << " | Recovery: " << profile.getRecoveryDays() << " days\n";
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

        Simulation sim;
        sim.reset(initial, std::random_device{}());
        sim.run(profiles[profileChoice - 1], days, true);
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
            Simulation sim;
            sim.reset(initial, static_cast<unsigned int>(900 + i));
            const SimulationSummary result = sim.run(profiles[i], days, false);

            std::cout << std::left << std::setw(32) << profiles[i].getName()
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
