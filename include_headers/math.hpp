#pragma once
#include <iostream>
#include <stdlib.h>
#include <ctime>

#include "customLogging.hpp"

inline int x = time(0);

inline int getRandomInt(int min, int max)
{
    // Generate a random integer between min and max (inclusive)
    srand(x); // Seed the random number generator with the current time

    return min + rand() % (max - min + 1);
}

inline int getRandomInt()
{

    srand(x); // Seed the random number generator with the current time

    return rand();
}