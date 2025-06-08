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
    int WORLD_SIZE = 4; // Size of the world in each dimension.
    std::vector<glm::vec3> cubePositions;
    std::vector<BlockType::BlockTypes> blockTypes;

    World() : cubePositions{
                  glm::vec3(0.0f, 0.0f, 0.0f),
                  glm::vec3(1.0f, 1.0f, 0.0f),
                  glm::vec3(2.0f, 1.0f, 0.0f),
                  glm::vec3(3.0f, 1.0f, 0.0f),
                  glm::vec3(4.0f, 1.0f, 0.0f),
                  glm::vec3(5.0f, 1.0f, 0.0f),
                  glm::vec3(6.0f, 1.0f, 0.0f),
                  glm::vec3(7.0f, 1.0f, 0.0f),
                  glm::vec3(8.0f, 1.0f, 0.0f),
                  glm::vec3(9.0f, 1.0f, 0.0f)}
    {
        log("World constructor called", CustomLogging::LogLevel::DEBUG);
        for (const auto &pos : cubePositions)
        {
            // For simplicity, we assume all blocks are of type DIRT.
            blockTypes.push_back(BlockType::BlockTypes::DIRT);
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
