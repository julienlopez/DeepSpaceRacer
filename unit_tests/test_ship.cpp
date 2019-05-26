#include <catch2/catch.hpp>

#include "ship.hpp"

TEST_CASE("Test Ship with only one thruster")
{

    SECTION("")
    {
        Ship ship({{}});
        CHECK(ship.numbeOfThrusters() == 1);
    }
}