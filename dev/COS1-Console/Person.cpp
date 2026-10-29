#include "Person.h"

Person::Person()
    : m_state(HealthState::Susceptible)
    , m_infectionAge(0)
{
}

HealthState Person::getState() const
{
    return m_state;
}

int Person::getInfectionAge() const
{
    return m_infectionAge;
}

void Person::infect()
{
    m_state = HealthState::Infected;
    m_infectionAge = 0;
}

void Person::recover()
{
    m_state = HealthState::Recovered;
    m_infectionAge = 0;
}

void Person::advanceInfection()
{
    if (m_state == HealthState::Infected)
    {
        ++m_infectionAge;
    }
}

bool Person::isSusceptible() const
{
    return m_state == HealthState::Susceptible;
}

bool Person::isInfected() const
{
    return m_state == HealthState::Infected;
}

bool Person::isRecovered() const
{
    return m_state == HealthState::Recovered;
}
