#include "ship.hpp"

Ship::Ship(const Units::Mass dry_mass)
    : m_dry_mass(dry_mass)
{
}

Units::Mass Ship::mass() const
{
    return m_dry_mass;
}
