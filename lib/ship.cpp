#include "ship.hpp"

#include <gsl/gsl_assert>

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

Vector2d<Units::Force> Ship::thrust() const
{
    using boost::units::si::newtons;
    Vector2d<Units::Force> res{{0 * newtons, 0 * newtons}};
    for(const auto i : range(m_thrusters.size()))
        res += thrust(i);
    return res;
}

Vector2d<Units::Force> Ship::thrust(const ThrusterIndex index) const
{
    Expects(index < numbeOfThrusters());
    const auto& thruster = m_thrusters[index];
    return -thruster.thruster.throttle() * castVectorTo<Units::Force>(thruster.position);
}

void Ship::setThrust(const ThrusterIndex index, const double throttle)
{
    Expects(index < numbeOfThrusters());
    m_thrusters[index].thruster.setThrottle(throttle);
}
