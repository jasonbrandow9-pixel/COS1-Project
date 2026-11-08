#include "Person.h"
#include "Simulation.h"
#include "VirusProfile.h"

#include <fstream>
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
            std::cout << "Enter a number between " << minimum << " and " << maximum << ": ";
            if (std::cin >> choice && choice >= minimum && choice <= maximum)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                return choice;
            }

            std::cout << kRed << "That is not a valid choice. Please enter a whole number from "
                      << minimum << " to " << maximum << ".\n" << kReset;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    bool readYesNo()
    {
        while (true)
        {
            std::cout << "(y/n): ";
            std::string input;
            std::getline(std::cin, input);
            if (input == "y" || input == "Y")
            {
                return true;
            }
            if (input == "n" || input == "N")
            {
                return false;
            }
            std::cout << kRed << "Please enter y or n.\n" << kReset;
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

    void saveResults(const SimulationSummary& summary, const VirusProfile& profile, unsigned int seed)
    {
        std::ofstream file("outbreak_report.txt");
        if (!file)
        {
            std::cout << kRed << "Could not create outbreak_report.txt\n" << kReset;
            return;
        }

        file << "Virus Spread Lab - Outbreak Report\n";
        file << "Profile: " << profile.getName() << "\n";
        file << "Seed: " << seed << "\n";
        file << "Days run: " << summary.daysRun << "\n";
        file << "Peak infected: " << summary.peakInfected << "\n";
        file << "Final infected: " << summary.finalInfected << "\n";
        file << "Final recovered: " << summary.finalRecovered << "\n";
        file << "Total population: " << summary.totalPopulation << "\n";

        std::cout << "Saved results to outbreak_report.txt\n";
    }

    void runInteractiveSimulation(const std::vector<VirusProfile>& profiles)
    {
        bool playAgain = true;
        while (playAgain)
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

            std::cout << "\nRun another simulation with different settings?\n";
            std::cout << "  1. Yes, run again\n";
            std::cout << "  2. No, return to main menu\n";
            playAgain = (readMenuChoice(1, 2) == 1);
        }
        std::cout << "\nUse a specific seed? ";
        unsigned int seed = 0;
        if (readYesNo())
        {
            std::cout << "Enter seed number: ";
            seed = static_cast<unsigned int>(readMenuChoice(0, 999999));
        }
        else
        {
            seed = std::random_device{}();
        }

        Simulation sim;
        sim.reset(initial, seed);
        const SimulationSummary summary = sim.run(profiles[profileChoice - 1], days, true);

        std::cout << "\nSave results to file? ";
        if (readYesNo())
        {
            saveResults(summary, profiles[profileChoice - 1], seed);
        }

        pauseForUser();
    }

    void quickRun(const std::vector<VirusProfile>& profiles)
    {
        std::cout << "\n" << kYellow << "QUICK RUN" << kReset << "\n";
        std::cout << "Using defaults: Seasonal-flu style, 30 days, 3 initial infected, random seed.\n";

        const unsigned int seed = std::random_device{}();
        Simulation sim;
        sim.reset(3, seed);
        const SimulationSummary summary = sim.run(profiles[1], 30, true);

        std::cout << "\nSave results to file? ";
        if (readYesNo())
        {
            saveResults(summary, profiles[1], seed);
        }

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
                  << "  2. Quick run (defaults)\n"
                  << "  3. Compare illustrative profiles\n"
                  << "  4. Learn how the model works\n"
                  << "  5. Exit\n";

        switch (readMenuChoice(1, 5))
        {
        case 1:
            runInteractiveSimulation(profiles);
            break;
        case 2:
            quickRun(profiles);
            break;
        case 3:
            compareProfiles(profiles);
            break;
        case 4:
            explainModel();
            break;
        case 5:
            running = false;
            break;
        }
    }

    std::cout << "\nKeep learning, keep testing, and keep questioning the model.\n";
    return 0;
}
