#pragma once

namespace BlockType
{
    enum BlockTypes
    {
        EMPTY,
        DIRT,
        GRASS,
        WATER
    };

    inline const char *blockTypeToString(BlockTypes type)
    {
        switch (type)
        {
        case EMPTY:
            return "EMPTY";
        case DIRT:
            return "DIRT";
        case GRASS:
            return "GRASS";
        case WATER:
            return "WATER";
        }
        return "UNKNOWN";
    }
}