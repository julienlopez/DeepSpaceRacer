#pragma once

#include "thruster.hpp"

#include <vector>

class Ship
{
public:
    struct ThrusterState
    {
        Thruster thruster;
        Vector2d<Units::Length> position;
        Units::Angle m_orientation;
    };

    using ThrusterContainer_t = std::vector<ThrusterState>;

    using ThrusterIndex = std::size_t;

    Ship(ThrusterContainer_t thrusters, const Units::Mass dry_mass);

    ~Ship() = default;

    Units::Mass mass() const;

    std::size_t numbeOfThrusters() const;

    Vector2d<Units::Force> thrust() const;

    void setThrust(const ThrusterIndex index, const double throttle);

private:
    const ThrusterContainer_t m_thrusters;
    const Units::Mass m_dry_mass;
};
