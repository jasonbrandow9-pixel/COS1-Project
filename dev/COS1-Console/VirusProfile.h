#pragma once

#include <string>

class VirusProfile
{
public:
    VirusProfile(const std::string& name,
                 const std::string& description,
                 int contactsPerDay,
                 double transmissionChance,
                 int recoveryDays);

    const std::string& getName() const;
    const std::string& getDescription() const;
    int getContactsPerDay() const;
    double getTransmissionChance() const;
    int getRecoveryDays() const;

private:
    std::string m_name;
    std::string m_description;
    int m_contactsPerDay;
    double m_transmissionChance;
    int m_recoveryDays;
};
