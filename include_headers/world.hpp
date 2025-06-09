#pragma once
#include <vector>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "customLogging.hpp"
// #include "worldGenerator_A.hpp"
#include "blockType.hpp"

class World
{
public:
    // Actual world size is WORLD_SIZE^3
    int WORLD_SIZE = 2; // Size of the world in each dimension.
    std::vector<glm::vec3> cubePositions;
    std::vector<BlockType::BlockTypes> blockTypes;

    World()
    {
        log("World constructor called", CustomLogging::LogLevel::DEBUG);
        for (const auto &pos : cubePositions)
        {
            // For simplicity, we assume all blocks are of type DIRT.
            // blockTypes.push_back(BlockType::BlockTypes::DIRT);
        }
    }

    /**
     * @brief Returns a vector of positions of all blocks in the world.
     */
    std::vector<glm::vec3> getWorldBlocksLoc();

    /**
     * @brief Returns a vector of block types for each block in the world.
     */
    std::vector<BlockType::BlockTypes> getBlockTypes();
};
