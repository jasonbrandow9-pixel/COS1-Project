#include "VirusProfile.h"

VirusProfile::VirusProfile(const std::string& name,
                           const std::string& description,
                           int contactsPerDay,
                           double transmissionChance,
                           int recoveryDays)
    : m_name(name)
    , m_description(description)
    , m_contactsPerDay(contactsPerDay)
    , m_transmissionChance(transmissionChance)
    , m_recoveryDays(recoveryDays)
{
}

const std::string& VirusProfile::getName() const
{
    return m_name;
}

const std::string& VirusProfile::getDescription() const
{
    return m_description;
}

int VirusProfile::getContactsPerDay() const
{
    return m_contactsPerDay;
}

double VirusProfile::getTransmissionChance() const
{
    return m_transmissionChance;
}

int VirusProfile::getRecoveryDays() const
{
    return m_recoveryDays;
}
