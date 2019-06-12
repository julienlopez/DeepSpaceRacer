#pragma once

#include "linear_algebra/matrix.hpp"

#include <boost/units/quantity.hpp>

#include <boost/units/systems/si/energy.hpp>
#include <boost/units/systems/si/force.hpp>
#include <boost/units/systems/si/length.hpp>
#include <boost/units/systems/si/mass.hpp>
#include <boost/units/systems/si/plane_angle.hpp>
#include <boost/units/systems/si/velocity.hpp>

template <class T> using Vector2d = LinearAlgebra::Matrix<T, 2, 1>;

const double pi = 3.14159265359;

namespace Units
{

using Angle = boost::units::quantity<boost::units::si::plane_angle>;

using Force = boost::units::quantity<boost::units::si::force>;

using Length = boost::units::quantity<boost::units::si::length>;

using Mass = boost::units::quantity<boost::units::si::mass>;

using Velocity = boost::units::quantity<boost::units::si::velocity>;

} // namespace Units

template <class T, class U> Vector2d<T> castVectorTo(const Vector2d<U>& vector)
{
    typename Vector2d<T>::Storage_t res;
    for(const auto i : range(res.size()))
        res[i] = T::from_value(vector(i).value()); // TODO find a better way?
    return Vector2d<T>{res};
}
