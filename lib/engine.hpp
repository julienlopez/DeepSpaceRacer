#pragma once

#include <vector>

struct Ship;

class Engine
{
public:
    Engine() = default;

    ~Engine() = default;

    std::size_t numbeOfShips() const;

};