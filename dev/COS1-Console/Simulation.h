#pragma once

#include "Person.h"
#include "VirusProfile.h"
#include <random>
#include <string>
#include <vector>

struct SimulationSummary
{
    int daysRun = 0;
    int peakInfected = 0;
    int finalInfected = 0;
    int finalRecovered = 0;
    int totalPopulation = 0;
};

class Simulation
{
public:
    static constexpr int Width = 30;
    static constexpr int Height = 14;
    static constexpr int Population = Width * Height;

    Simulation();

    void reset(int initialInfected, unsigned int seed);
    SimulationSummary run(const VirusProfile& profile, int days, bool showDailyReport);

    void printGrid() const;
    std::size_t countState(HealthState state) const;

private:
    int neighborIndex(int index, int direction) const;

    std::vector<Person> m_people;
    std::mt19937 m_generator;
};
