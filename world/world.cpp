#include "world.hpp"
#include "customLogging.hpp"

std::vector<glm::vec3> World::getWorldBlocksLoc()
{
    return cubePositions;
}

std::vector<BlockType::BlockTypes> World::getBlockTypes()
{

    return blockTypes;
}
