#include "thruster.hpp"

#include <gsl/gsl_assert>

Thruster::Thruster(Units::Force full_thrust)
    : m_full_thrust(std::move(full_thrust))
{
}

Units::Force Thruster::thrust() const
{
    return m_throttle * m_full_thrust;
}

double Thruster::throttle() const
{
    return m_throttle;
}

/**
 * @pre 0 <= throttle_ <= 1
 */
void Thruster::setThrottle(const double throttle_)
{
    Expects(0. <= throttle_ && throttle_ <= 1.);
    m_throttle = throttle_;
}
