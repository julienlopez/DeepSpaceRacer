#pragma once

#include "units.hpp"

struct Thruster
{
    const Units::Force full_thrust;
    double throttle;
};

class Ship
{
public:
    using ThrusterContainer_t = std::vector<Thruster>;

    Ship(ThrusterContainer_t thrusters, const Units::Mass dry_mass = 1000 * boost::units::si::kilograms);

    ~Ship() = default;

    Units::Mass mass() const;

	std::size_t numbeOfThrusters() const;

private:
    const ThrusterContainer_t m_thrusters;
    const Units::Mass m_dry_mass;
};
