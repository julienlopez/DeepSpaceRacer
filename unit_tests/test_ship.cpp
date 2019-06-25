#include "ship.hpp"

#include <boost/units/io.hpp>

std::ostream& operator<<(std::ostream& os, const Vector2d<Units::Force>& value)
{
    os << "(" << value(0) << ", " << value(1) << ")";
    return os;
}

#include <catch2/catch.hpp>

namespace
{

template <class T> class ApproxVectorMatcher : public Catch::MatcherBase<Vector2d<T>>
{
public:
    ApproxVectorMatcher(const Vector2d<T>& expected_value, const double delta)
        : m_expected_value(expected_value)
        , m_delta(delta)
    {
    }

    bool match(const Vector2d<T>& i) const override
    {
        return std::abs((m_expected_value(0) - i(0)).value()) < m_delta
               && std::abs((m_expected_value(1) - i(1)).value()) < m_delta;
    }

    virtual std::string describe() const override
    {
        std::ostringstream ss;
        ss << "is approximately equal to " << m_expected_value;
        return ss.str();
    }

private:
    const Vector2d<T> m_expected_value;
    const double m_delta;
};

template <class T> inline ApproxVectorMatcher<T> ApproxVector(const Vector2d<T>& vector, const double delta = 0.001)
{
    return ApproxVectorMatcher<T>{vector, delta};
}
} // namespace

TEST_CASE("Test Ship with only one thruster", "[engine]")
{
    using namespace boost::units::si;

    SECTION("Basic ship with a thruster pointing straight up")
    {
        Ship ship({{Thruster{1 * newtons}, {{0 * meters, -1 * meters}}, pi / 2 * radians}}, 1000 * kilograms);
        REQUIRE(ship.numbeOfThrusters() == 1);
        ship.setThrust(0, 0.);
        CHECK_THAT(ship.thrust(), ApproxVector<Units::Force>({{0 * newtons, 0 * newtons}}));
        ship.setThrust(0, 1.);
        CHECK_THAT(ship.thrust(), ApproxVector<Units::Force>({{0 * newtons, 1 * newtons}}));
    }

    SECTION("Basic ship with a thruster pointing straight down")
    {
        Ship ship({{Thruster{1 * newtons}, {{0 * meters, 1 * meters}}, 3 * pi / 2 * radians}}, 1000 * kilograms);
        REQUIRE(ship.numbeOfThrusters() == 1);
        ship.setThrust(0, 1.);
        CHECK_THAT(ship.thrust(), ApproxVector<Units::Force>({{0 * newtons, -1 * newtons}}));
    }

    SECTION("Basic ship with a thruster pointing straight left")
    {
        Ship ship({{Thruster{1 * newtons}, {{-1 * meters, 0 * meters}}, 0 * radians}}, 1000 * kilograms);
        REQUIRE(ship.numbeOfThrusters() == 1);
        ship.setThrust(0, 1.);
        CHECK_THAT(ship.thrust(), ApproxVector<Units::Force>({{1 * newtons, 0 * newtons}}));
    }

    SECTION("Basic ship with a thruster pointing straight right")
    {
        Ship ship({{Thruster{1 * newtons}, {{1 * meters, 0 * meters}}, pi * radians}}, 1000 * kilograms);
        REQUIRE(ship.numbeOfThrusters() == 1);
        ship.setThrust(0, 1.);
        CHECK_THAT(ship.thrust(), ApproxVector<Units::Force>({{-1 * newtons, 0 * newtons}}));
        CHECK_THAT(ship.thrust(), ApproxVector<Units::Force>({{-1 * newtons, 0 * newtons}}));
    }
}

TEST_CASE("Test Ship with two thrusters", "[engine]")
{
    using namespace boost::units::si;

    SECTION("Basic ship with two thrusters pointing straight up")
    {
        Ship ship({{Thruster{1 * newtons}, {{-1 * meters, 0 * meters}}, pi / 2 * radians},
                   {Thruster{1 * newtons}, {{1 * meters, 0 * meters}}, pi / 2 * radians}},
                  1000 * kilograms);
        REQUIRE(ship.numbeOfThrusters() == 2);
        ship.setThrust(0, 1.);
        ship.setThrust(1, 1.);
        CHECK_THAT(ship.thrust(), ApproxVector<Units::Force>({{0 * newtons, 2 * newtons}}));
    }

    SECTION("Basic ship with two thrusters pointing straight down")
    {
        Ship ship({{Thruster{1 * newtons}, {{1 * meters, 0 * meters}}, 3 * pi / 2 * radians},
                   {Thruster{1 * newtons}, {{-1 * meters, 0 * meters}}, 3 * pi / 2 * radians}},
                  1000 * kilograms);
        REQUIRE(ship.numbeOfThrusters() == 2);
        ship.setThrust(0, 1.);
        ship.setThrust(1, 1.);
        CHECK_THAT(ship.thrust(), ApproxVector<Units::Force>({{0 * newtons, -2 * newtons}}));
    }

    SECTION("Basic ship with two thrusters pointing straight left")
    {
        Ship ship({{Thruster{1 * newtons}, {{0 * meters, -1 * meters}}, 0 * radians},
                   {Thruster{1 * newtons}, {{0 * meters, 1 * meters}}, 0 * radians}},
                  1000 * kilograms);
        REQUIRE(ship.numbeOfThrusters() == 2);
        ship.setThrust(0, 1.);
        ship.setThrust(1, 1.);
        CHECK_THAT(ship.thrust(), ApproxVector<Units::Force>({{2 * newtons, 0 * newtons}}));
    }

    SECTION("Basic ship with two thrusters pointing straight right")
    {
        Ship ship({{Thruster{1 * newtons}, {{0 * meters, 1 * meters}}, pi * radians},
                   {Thruster{1 * newtons}, {{0 * meters, -1 * meters}}, pi * radians}},
                  1000 * kilograms);
        REQUIRE(ship.numbeOfThrusters() == 2);
        ship.setThrust(0, 1.);
        ship.setThrust(1, 1.);
        CHECK_THAT(ship.thrust(), ApproxVector<Units::Force>({{-2 * newtons, 0 * newtons}}));
    }
}