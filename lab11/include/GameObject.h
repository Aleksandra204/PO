#pragma once

#include <vector>

// Base class for game objects
class GameObject {
public:
    virtual void update() = 0;
};