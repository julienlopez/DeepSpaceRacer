#pragma once

#include <boost/units/quantity.hpp>

#include <boost/units/systems/si/plane_angle.hpp>
#include <boost/units/systems/si/energy.hpp>
#include <boost/units/systems/si/force.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/velocity.hpp>

#include <Eigen/Dense>

template<class T>
using Vector2d = Eigen::Matrix<T, 2, 1>;

namespace Units
{

using Angle = boost::units::quantity<boost::units::si::plane_angle>;

using Force = boost::units::quantity<boost::units::si::force>;

using Length = boost::units::quantity<boost::units::si::length>;

using Mass = boost::units::quantity<boost::units::si::mass>;

using Velocity = boost::units::quantity<boost::units::si::velocity>;

}
