#include "glrenderer.hpp"
#include "program.hpp"
#include <GLFW/glfw3.h>
#include <cmath>

void renderWindow(GLFWwindow *window)
{
    // Generate shader program and get VAO/VBO handles
    RenderData renderData = genShaderProgram();

    // // -----------------------------------------------------------------------------
    // // checking GL_MAX_VERTEX_ATTRIBS
    // int nrAttributes;
    // glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &nrAttributes);
    // std::cout << "Maximum nr of vertex attributes supported: " << nrAttributes;
    // // -----------------------------------------------------------------------------

    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

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

        // Draw the rectangle (two triangles)
        // glDrawElements(GL_POINTS, 6, GL_UNSIGNED_INT, 0);
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
