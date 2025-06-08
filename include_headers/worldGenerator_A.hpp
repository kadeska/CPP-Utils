#pragma once
#include "customLogging.hpp"
#include "world.hpp"
#include "blockType.hpp"

class worldGenerator_A
{
public:
    World world;
    worldGenerator_A();
    World generateWorld(int seed, int width, int height, int depth);

    int index(int x, int y, int z, int width, int height)
    {
        return x + width * (y + height * z);
    }
};