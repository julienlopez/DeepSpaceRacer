#pragma once

#include "ship.hpp"

#include <vector>

class Engine
{
public:
    struct ShipState
    {
        Ship ship;
        Units::Angle orientation;
        Vector2d<Units::Length> position;
        Vector2d<Units::Velocity> speed;
    };

    using ShipStateContainer_t = std::vector<ShipState>;

    Engine() = default;

    ~Engine() = default;

    std::size_t numbeOfShips() const;
};