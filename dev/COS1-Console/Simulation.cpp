#include "Simulation.h"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <limits>

namespace
{
    const std::string kGreen = "\x1B[32m";
    const std::string kYellow = "\x1B[33m";
    const std::string kCyan = "\x1B[36m";
    const std::string kRed = "\x1B[31m";
    const std::string kReset = "\x1B[0m";
}

Simulation::Simulation()
    : m_people(Population)
    , m_generator(std::random_device{}())
{
}

void Simulation::reset(int initialInfected, unsigned int seed)
{
    m_generator.seed(seed);
    m_people.assign(Population, Person());

    std::uniform_int_distribution<int> startDistribution(0, Population - 1);
    int seeded = 0;
    while (seeded < initialInfected)
    {
        const int index = startDistribution(m_generator);
        if (m_people[index].isSusceptible())
        {
            m_people[index].infect();
            ++seeded;
        }
    }
}

std::size_t Simulation::countState(HealthState state) const
{
    return static_cast<std::size_t>(std::count_if(m_people.begin(), m_people.end(),
        [state](const Person& person) { return person.getState() == state; }));
}

void Simulation::printGrid() const
{
    std::cout << "\n" << kYellow << "LIVE GRID" << kReset << "\n";
    std::cout << "  " << kGreen << "." << kReset << " susceptible   "
              << kRed << "#" << kReset << " infected   "
              << kCyan << "+" << kReset << " recovered\n\n";

    for (int row = 0; row < Height; ++row)
    {
        std::cout << "  ";
        for (int column = 0; column < Width; ++column)
        {
            const Person& person = m_people[row * Width + column];
            if (person.isInfected())
            {
                std::cout << kRed << '#' << kReset;
            }
            else if (person.isRecovered())
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

int Simulation::neighborIndex(int index, int direction) const
{
    const int row = index / Width;
    const int column = index % Width;
    const int nextRow = row + (direction == 0 ? -1 : direction == 1 ? 1 : 0);
    const int nextColumn = column + (direction == 2 ? -1 : direction == 3 ? 1 : 0);

    if (nextRow < 0 || nextRow >= Height || nextColumn < 0 || nextColumn >= Width)
    {
        return -1;
    }
    return nextRow * Width + nextColumn;
}

SimulationSummary Simulation::run(const VirusProfile& profile, int days, bool showDailyReport)
{
    SimulationSummary summary;
    summary.totalPopulation = Population;
    summary.peakInfected = static_cast<int>(countState(HealthState::Infected));

    if (showDailyReport)
    {
        std::cout << "\n" << kYellow << "OUTBREAK REPORT: " << profile.getName() << kReset << "\n";
        std::cout << "This is a simplified educational model, not a medical forecast.\n\n";
        printGrid();
        std::cout << "\nDay  Susceptible  Infected  Recovered  New infections  Spread factor\n";
        std::cout << "---  -----------  --------  ---------  ---------------  -------------\n";
    }

    std::uniform_int_distribution<int> directionDistribution(0, 3);
    std::uniform_real_distribution<double> chanceDistribution(0.0, 1.0);

    for (int day = 1; day <= days; ++day)
    {
        const int infectedBefore = static_cast<int>(countState(HealthState::Infected));
        if (infectedBefore == 0)
        {
            break;
        }

        std::vector<Person> next = m_people;
        int newInfections = 0;

        for (int index = 0; index < Population; ++index)
        {
            if (!m_people[index].isInfected())
            {
                continue;
            }

            for (int contact = 0; contact < profile.getContactsPerDay(); ++contact)
            {
                const int neighbor = neighborIndex(index, directionDistribution(m_generator));
                if (neighbor >= 0 &&
                    m_people[neighbor].isSusceptible() &&
                    next[neighbor].isSusceptible() &&
                    chanceDistribution(m_generator) < profile.getTransmissionChance())
                {
                    next[neighbor].infect();
                    ++newInfections;
                }
            }

            next[index].advanceInfection();
            if (next[index].getInfectionAge() >= profile.getRecoveryDays())
            {
                next[index].recover();
            }
        }

        m_people = std::move(next);
        const int infectedAfter = static_cast<int>(countState(HealthState::Infected));
        const int recovered = static_cast<int>(countState(HealthState::Recovered));
        summary.peakInfected = std::max(summary.peakInfected, infectedAfter);
        summary.daysRun = day;

        if (showDailyReport)
        {
            const double spreadFactor = infectedBefore == 0 ? 0.0 :
                static_cast<double>(newInfections) / infectedBefore;
            std::cout << std::setw(3) << day << "  "
                      << std::setw(11) << Population - infectedAfter - recovered << "  "
                      << std::setw(8) << infectedAfter << "  "
                      << std::setw(9) << recovered << "  "
                      << std::setw(15) << newInfections << "  "
                      << std::setw(13) << std::fixed << std::setprecision(2) << spreadFactor << '\n';

            if (day % 5 == 0 || infectedAfter == 0 || day == days)
            {
                printGrid();
            }
        }
    }

    summary.finalInfected = static_cast<int>(countState(HealthState::Infected));
    summary.finalRecovered = static_cast<int>(countState(HealthState::Recovered));
    return summary;
}
