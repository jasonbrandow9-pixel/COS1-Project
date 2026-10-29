#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>

struct Milestone
{
    std::string title;
    std::string goal;
    bool completed;
};

namespace
{
    const std::string kGreen = "\x1B[32m";
    const std::string kYellow = "\x1B[33m";
    const std::string kCyan = "\x1B[36m";
    const std::string kRed = "\x1B[31m";
    const std::string kReset = "\x1B[0m";

    void printBanner()
    {
        std::cout << kCyan
                  << "\n  ================================================================\n"
                  << "     COS1 PROJECT & PORTFOLIO TRACKER\n"
                  << "     Build small. Learn deeply. Ship consistently.\n"
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

    std::string readRequiredText(const std::string& prompt)
    {
        std::string value;
        do
        {
            std::cout << prompt;
            std::getline(std::cin, value);
            if (value.empty())
            {
                std::cout << kRed << "This field cannot be empty.\n" << kReset;
            }
        } while (value.empty());
        return value;
    }

    void printProgress(std::size_t completed, std::size_t total)
    {
        const int width = 30;
        const double ratio = total == 0 ? 0.0 : static_cast<double>(completed) / total;
        const int filled = static_cast<int>(ratio * width);

        std::cout << "Progress [";
        for (int i = 0; i < width; ++i)
        {
            std::cout << (i < filled ? '#' : '-');
        }
        std::cout << "] " << std::fixed << std::setprecision(0) << ratio * 100 << "%\n";
    }

    void showDashboard(const std::vector<Milestone>& milestones)
    {
        std::size_t completed = 0;
        for (const Milestone& milestone : milestones)
        {
            if (milestone.completed)
            {
                ++completed;
            }
        }

        std::cout << "\n" << kYellow << "PROJECT DASHBOARD" << kReset << "\n";
        std::cout << "Milestones: " << milestones.size() << "\n";
        std::cout << "Completed:  " << completed << "\n";
        printProgress(completed, milestones.size());

        if (completed == milestones.size())
        {
            std::cout << kGreen << "Excellent work: every milestone is complete!\n" << kReset;
        }
        else
        {
            std::cout << "Next focus: keep one milestone moving forward.\n";
        }
    }

    void listMilestones(const std::vector<Milestone>& milestones)
    {
        std::cout << "\n" << kYellow << "MILESTONE BOARD" << kReset << "\n";
        if (milestones.empty())
        {
            std::cout << "No milestones yet. Add one from the main menu.\n";
            return;
        }

        for (std::size_t i = 0; i < milestones.size(); ++i)
        {
            const Milestone& milestone = milestones[i];
            const std::string status = milestone.completed ? kGreen + "DONE" + kReset : kYellow + "IN PROGRESS" + kReset;
            std::cout << "  " << (i + 1) << ". " << milestone.title << " [" << status << "]\n";
            std::cout << "     Goal: " << milestone.goal << "\n";
        }
    }

    void addMilestone(std::vector<Milestone>& milestones)
    {
        std::cout << "\n" << kYellow << "ADD MILESTONE" << kReset << "\n";
        Milestone milestone{};
        milestone.title = readRequiredText("Milestone name: ");
        milestone.goal = readRequiredText("What does success look like? ");
        milestone.completed = false;
        milestones.push_back(milestone);
        std::cout << kGreen << "Milestone added to your portfolio plan.\n" << kReset;
    }

    void completeMilestone(std::vector<Milestone>& milestones)
    {
        std::vector<std::size_t> openMilestones;
        for (std::size_t i = 0; i < milestones.size(); ++i)
        {
            if (!milestones[i].completed)
            {
                openMilestones.push_back(i);
            }
        }

        if (openMilestones.empty())
        {
            std::cout << kGreen << "All milestones are already complete.\n" << kReset;
            return;
        }

        std::cout << "\n" << kYellow << "MARK MILESTONE COMPLETE" << kReset << "\n";
        for (std::size_t i = 0; i < openMilestones.size(); ++i)
        {
            std::cout << "  " << (i + 1) << ". " << milestones[openMilestones[i]].title << "\n";
        }

        const int selection = readMenuChoice(1, static_cast<int>(openMilestones.size()));
        milestones[openMilestones[selection - 1]].completed = true;
        std::cout << kGreen << "Great job! Milestone marked complete.\n" << kReset;
    }

    std::vector<Milestone> createStarterMilestones()
    {
        return {
            {"Set up version control", "Keep the repository organized and commit meaningful progress.", true},
            {"Build the first C++ feature", "Create an interactive program that solves a real problem.", false},
            {"Document the project", "Explain the purpose, features, and build steps clearly.", false},
            {"Prepare a portfolio update", "Summarize challenges, accomplishments, and next steps.", false}
        };
    }
}

int main()
{
    std::vector<Milestone> milestones = createStarterMilestones();
    printBanner();

    bool running = true;
    while (running)
    {
        std::cout << "\n" << kCyan << "MAIN MENU" << kReset << "\n"
                  << "  1. View dashboard\n"
                  << "  2. View milestone board\n"
                  << "  3. Add a milestone\n"
                  << "  4. Mark a milestone complete\n"
                  << "  5. Reset demo milestones\n"
                  << "  6. Exit\n";

        switch (readMenuChoice(1, 6))
        {
        case 1:
            showDashboard(milestones);
            pauseForUser();
            break;
        case 2:
            listMilestones(milestones);
            pauseForUser();
            break;
        case 3:
            addMilestone(milestones);
            pauseForUser();
            break;
        case 4:
            completeMilestone(milestones);
            pauseForUser();
            break;
        case 5:
            milestones = createStarterMilestones();
            std::cout << kGreen << "Demo milestones restored.\n" << kReset;
            pauseForUser();
            break;
        case 6:
            running = false;
            break;
        }
    }

    std::cout << "\nThanks for building with purpose. Keep shipping!\n";
    return 0;
}
