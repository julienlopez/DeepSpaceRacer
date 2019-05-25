#pragma once

#include "units.hpp"

class Ship
{
public:
    Ship(const Units::Mass dry_mass = 1000 * boost::units::si::kilograms);

    ~Ship() = default;

    Units::Mass mass() const;
    
private:
    const Units::Mass m_dry_mass;
};
