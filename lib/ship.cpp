#include "ship.hpp"

Ship::Ship(ThrusterContainer_t thrusters, const Units::Mass dry_mass)
    : m_thrusters(std::move(thrusters))
    , m_dry_mass(dry_mass)
{
}

Units::Mass Ship::mass() const
{
    return m_dry_mass;
}

std::size_t Ship::numbeOfThrusters() const
{
    return m_thrusters.size();
}
