#include "worldGenerator_A.hpp"
#include "world.hpp"
#include "customLogging.hpp"
#include "math.hpp"

worldGenerator_A::worldGenerator_A()
{
    // Constructor implementation
    log("worldGenerator_A constructor called", CustomLogging::LogLevel::DEBUG);
}
World worldGenerator_A::generateWorld(int seed, int width, int height, int depth)
{
    log("Generating world with seed: " + std::to_string(seed) +
            ", width: " + std::to_string(width) +
            ", height: " + std::to_string(height) +
            ", depth: " + std::to_string(depth),
        CustomLogging::LogLevel::DEBUG);

    // helper.log(3, "generating world");
    // Create a world object with the specified size.
    // world = World();
    // Set the world size.
    // world.WORLD_SIZE = width * height * depth;

    // resize the vectors to more than enough space for the blocks.
    // Will probably try to optimize this later, to resize the vectors
    // to the exact size or slightly more, and allow dynamic resizing.
    size_t total = width * height * depth;
    world.cubePositions.resize(total);
    world.blockTypes.resize(total);

    // Iterate over every coordinate in the 3D space.
    for (int z = 0; z < width; ++z)
    {
        for (int y = 0; y < height; ++y)
        {
            for (int x = 0; x < depth; ++x)
            { // -----------world generation-----------------
                // debug log of indexing
                // helper.log(4, std::string("indexing ( " + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(x)));
                // Calculate the index for the current coordinates
                int idx = index(x, y, z, width, height);
                glm::vec3 blockLoc = world.getWorldBlocksLoc()[idx];

                // fill vectors
                world.cubePositions[idx] = glm::vec3(x, y, z);
                world.blockTypes[idx] = BlockType::BlockTypes::EMPTY;

                // log the position and type of the block
                log("Block at (" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) +
                        ") initialized with type: " +
                        std::to_string(static_cast<int>(world.blockTypes[idx])),
                    CustomLogging::LogLevel::DEBUG);

                // Add noise generation here ...
                // int height = noiseGenerator.getHeight(x, y); // Use noise to determine height
                // For now, just set the block type based on the z-coordinate.

                // Simple generation: the bottom layer is DIRT, the next layer is GRASS.
                if (y == 0)
                {
                    log("setting this block to dirt", CustomLogging::LogLevel::DEBUG);
                    // set the block type for this layer to DIRT

                    // get the location of the current block

                    // set the blocktype
                    // world.getBlockTypes()[idx] = BlockType::BlockTypes::DIRT;
                    world.blockTypes[idx] = BlockType::BlockTypes::DIRT;
                    // world.getCube(x, y, z).blockType = BlockType::BlockTypes::DIRT;
                }
                if (getRandomInt(0, 10) == 2 && y == 1)
                {
                    // set the block type for this layer to WATER
                    log("setting this block to water", CustomLogging::LogLevel::DEBUG);
                    world.blockTypes[idx] = BlockType::BlockTypes::DIRT;
                    // world.getCube(x, y, z).blockType = BlockType::BlockTypes::WATER;
                }
                // else if (z == 1)
                // {
                //     // set the block type for this layer to GRASS
                //     glm::vec3 blockLoc = world.getWorldBlocksLoc()[idx];
                //     world.getBlockTypes()[idx] = BlockType::BlockTypes::GRASS;
                //     // world.getCube(x, y, z).blockType = BlockType::BlockTypes::GRASS;
                // }
                // Other layers remain EMPTY (default constructed).
            }
        }
    }

    return world;
}
