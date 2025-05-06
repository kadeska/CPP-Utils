#include "glrenderer.hpp"
#include "program.hpp"
#include <GLFW/glfw3.h>

void renderWindow(GLFWwindow *window)
{
    // Generate shader program and get VAO/VBO handles
    RenderData renderData = genShaderProgram();

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Use our shader program and bind VAO
        glUseProgram(renderData.shaderProgram);
        glBindVertexArray(renderData.VAO);

        // Draw the rectangle (two triangles)
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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
