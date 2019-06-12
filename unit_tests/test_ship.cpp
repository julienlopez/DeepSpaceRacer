#include "ship.hpp"

#include <boost/units/io.hpp>

std::ostream& operator<<(std::ostream& os, const Vector2d<Units::Force>& value)
{
    os << "(" << value(0) << ", " << value(1) << ")";
    return os;
}

#include <catch2/catch.hpp>

TEST_CASE("Test Ship with only one thruster", "[engine]")
{
    using namespace boost::units::si;

    SECTION("Basic ship with a thruster pointing straight up")
    {
        Ship ship({{Thruster{1 * newtons}, {{0 * meters, -1 * meters}}, pi / 4 * radians}}, 1000 * kilograms);
        CHECK(ship.numbeOfThrusters() == 1);
        ship.setThrust(0, 0.);
        CHECK(ship.thrust() == Vector2d<Units::Force>{{0 * newtons, 0 * newtons}});
        ship.setThrust(0, 1.);
        CHECK(ship.thrust() == Vector2d<Units::Force>{{0 * newtons, 1 * newtons}});
    }
}