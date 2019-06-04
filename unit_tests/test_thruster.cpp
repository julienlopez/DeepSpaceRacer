#include <catch2/catch.hpp>

#include "thruster.hpp"

TEST_CASE("TestThruster", "[engine]")
{

    SECTION("Basic throttle operation")
    {
        using boost::units::si::newtons;
        const Units::Force full_thrust = 100 * newtons;
        Thruster thruster(full_thrust);
        CHECK(thruster.throttle() == 0.);
        CHECK(thruster.thrust() == 0. * newtons);
        thruster.setThrottle(1.);
        CHECK(thruster.throttle() == 1.);
        CHECK(thruster.thrust() == full_thrust);
    }
}
