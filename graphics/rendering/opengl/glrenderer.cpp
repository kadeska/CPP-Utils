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

    World world = World();
    worldGenerator_A worldGen = worldGenerator_A();
    world = worldGen.generateWorld(0, world.WORLD_SIZE, world.WORLD_SIZE, world.WORLD_SIZE);

    while (!glfwWindowShouldClose(window))
    {
        processInput(window, cam);
        cam.view = glm::lookAt(cam.cameraPos, cam.cameraTarget, cam.up);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use our shader program and bind VAO
        glUseProgram(renderData.shaderProgram);
        // update the uniform color
        float timeValue = glfwGetTime();
        float greenValue = sin(timeValue) / 2.0f + 0.5f;
        int vertexColorLocation = glGetUniformLocation(renderData.shaderProgram, "ourColor");
        glUniform4f(vertexColorLocation, 0.0f, greenValue, 0.0f, 1.0f);
        glBindVertexArray(renderData.VAO);
        for (unsigned int i = 0; i < world.cubePositions.size(); i++)
        {
            glm::mat4 model = glm::mat4(1.0f);
            model = glm::translate(model, world.cubePositions[i]);
            float angle = 20.0f * i;
            // model = glm::rotate(model, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
            renderData.ourShader.setMat4("model", model);

            glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);
        }

        // create transformations
        glm::mat4 model = glm::mat4(1.0f); // make sure to initialize matrix to identity matrix first
        glm::mat4 view = cam.view;         // glm::mat4(1.0f);
        glm::mat4 projection = glm::perspective(glm::radians(45.0f),
                                                (float)W_width / (float)W_height,
                                                0.1f,
                                                100.0f); // glm::mat4(1.0f);
        // model = glm::rotate(model, glm::radians(-55.0f), glm::vec3(1.0f, 0.0f, 0.0f));
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
        // projection = glm::perspective(glm::radians(45.0f), (float)W_width / (float)W_height, 0.1f, 100.0f);
        // retrieve the matrix uniform locations
        unsigned int modelLoc = glGetUniformLocation(renderData.ourShader.ID, "model");
        unsigned int viewLoc = glGetUniformLocation(renderData.ourShader.ID, "view");
        // pass them to the shaders (3 different ways)
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
        glUniformMatrix4fv(viewLoc, 1, GL_FALSE, &view[0][0]);
        // note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
        renderData.ourShader.setMat4("projection", projection);

        // do stuff
        // cam.dostuff(); // makes cube rotate.
        // cam.processInput(window);
        view = cam.view;

        // Draw the rectangle (two triangles)
        // glDrawElements(GL_POINTS, 6, GL_UNSIGNED_INT, 0);
        glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

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
