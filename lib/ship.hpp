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
        Units::Angle orientation;
    };

    using ThrusterContainer_t = std::vector<ThrusterState>;

    using ThrusterIndex = std::size_t;

    Ship(ThrusterContainer_t thrusters, const Units::Mass dry_mass);

    ~Ship() = default;

    Units::Mass mass() const;

    std::size_t numbeOfThrusters() const;

    /**
    * @brief return the full thrust acting on the Ship
    */
    Vector2d<Units::Force> thrust() const;

    /**
     * @brief the thrust of a given thruster
     *
     * @pre index < numbeOfThrusters()
     */
    Vector2d<Units::Force> thrust(const ThrusterIndex index) const;

    /**
     * @pre index < numbeOfThrusters()
     * @pre 0 <= throttle_ <= 1
     */
    void setThrust(const ThrusterIndex index, const double throttle);

private:
    ThrusterContainer_t m_thrusters;
    const Units::Mass m_dry_mass;
};
