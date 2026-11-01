#pragma once

enum class HealthState
{
    Susceptible,
    Infected,
    Recovered
};

class Person
{
public:
    Person();

    HealthState getState() const;
    int getInfectionAge() const;

    void infect();
    void recover();
    void advanceInfection();

    bool isSusceptible() const;
    bool isInfected() const;
    bool isRecovered() const;

private:
    HealthState m_state;
    int m_infectionAge;
};
