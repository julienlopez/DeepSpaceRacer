#pragma once

#include "units.hpp"

class Thruster
{
public:
    Thruster(Units::Force full_thrust);

    ~Thruster() = default;

    Units::Force thrust() const;

    double throttle() const;

    /**
    * @pre 0 <= throttle_ <= 1
    */
    void setThrottle(const double throttle_);

private:
    const Units::Force m_full_thrust;
    double m_throttle = 0.;
};
