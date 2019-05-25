#include <catch2/catch.hpp>

#include "engine.hpp"

TEST_CASE("TestEngine")
{

    SECTION("A new engine doesn't have any ship")
    {
        Engine engine;
        CHECK(engine.numbeOfShips() == 0);
	}
}
