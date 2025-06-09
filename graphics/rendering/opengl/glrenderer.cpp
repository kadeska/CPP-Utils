#include "glrenderer.hpp"
#include "program.hpp"
#include <GLFW/glfw3.h>
#include <cmath>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "worldGenerator_A.hpp"

// #include "window.hpp"
#include "camera.hpp"
#include "world.hpp"

void renderWindow(GLFWwindow *window)
{
    // Generate shader program and get VAO/VBO handles
    RenderData renderData = genShaderProgram();

    Camera cam = Camera();

    // // -----------------------------------------------------------------------------
    // // checking GL_MAX_VERTEX_ATTRIBS
    // int nrAttributes;
    // glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    // std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes;
    // // -----------------------------------------------------------------------------

    // World world; // = World();
    worldGenerator_A worldGen = worldGenerator_A();
    // (0, world.WORLD_SIZE, world.WORLD_SIZE, world.WORLD_SIZE)
    worldGen.world = worldGen.generateWorld(0, 10, 10, 10);

    glEnable(GL_DEPTH_TEST);

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDisable(GL_CULL_FACE);
    while (!glfwWindowShouldClose(window))
    {
        processInput(window, cam);
        cam.view = glm::lookAt(cam.cameraPos, cam.cameraTarget, cam.up);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(renderData.shaderProgram);

        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(renderData.shaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);

        glBindVertexArray(renderData.VAO);

        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                (float)W_width / (float)W_height,
                                                0.1f, 100.0f);
        renderData.ourShader.setMat4("projection", projection);

        unsigned int viewLoc = glGetUniformLocation(renderData.ourShader.ID, "view");
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(cam.view));

        for (unsigned int i = 0; i < worldGen.world.cubePositions.size(); i++)
        {
            if (worldGen.world.getBlockTypes()[i] != BlockType::BlockTypes::EMPTY)
            {
                glm::mat4 model = glm::mat4(1.0f);
                model = glm::translate(model, worldGen.world.cubePositions[i]);
                renderData.ourShader.setMat4("model", model);

                glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
            }
            // glm::mat4 model = glm::mat4(1.0f);
            // model = glm::translate(model, worldGen.world.cubePositions[i]);
            // renderData.ourShader.setMat4("model", model);

            // glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        }

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Cleanup
    glDeleteVertexArrays(1, &renderData.VAO);
    glDeleteBuffers(1, &renderData.VBO);
    glDeleteBuffers(1, &renderData.EBO);
    glDeleteProgram(renderData.shaderProgram);

    glfwTerminate();
}
