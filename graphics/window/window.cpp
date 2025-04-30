/**
 * @file window.cpp
 * This is were you can create a window to display your graphics.
 */

#include "window.hpp"
#include "customLogging.hpp"

// Define the window variable
GLFWwindow *window = nullptr;

int initialize()
{

    // Initialize GLFW first
    if (!glfwInit())
    {
        CustomLogging::log("Failed to initialize GLFW", CustomLogging::LogLevel::ERROR, true);
        return -1;
    }

    // glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    return 0;
}

GLFWwindow *createWindow(int width, int height, std::string name)
{
    window = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
    if (window == NULL)
    {
        CustomLogging::log("Failed to create GLFW window", CustomLogging::LogLevel::ERROR, true);
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        CustomLogging::log("Failed to initialize GLAD", CustomLogging::LogLevel::ERROR, true);
        glfwDestroyWindow(window);
        glfwTerminate();
        return window;
    }
    glViewport(0, 0, width, height);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    return window;
}

void framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}