/**
 * @file window.cpp
 * This is were you can create a window to display your graphics.
 */

#include "window.hpp"
#include "customLogging.hpp"
#include "camera.hpp"

// Define the window variable
GLFWwindow *window = nullptr;

int W_width = 800;  // Default width
int W_height = 600; // Default height

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
    W_height = height;
    W_width = width;
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

void processInput(GLFWwindow *window, Camera &mainCam)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    const float cameraSpeed = 0.05f;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        mainCam.cameraPos += cameraSpeed * glm::normalize(mainCam.cameraTarget - mainCam.cameraPos);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        mainCam.cameraPos -= cameraSpeed * glm::normalize(mainCam.cameraTarget - mainCam.cameraPos);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        mainCam.cameraPos -= glm::normalize(glm::cross(mainCam.cameraTarget - mainCam.cameraPos, mainCam.up)) * cameraSpeed;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        mainCam.cameraPos += glm::normalize(glm::cross(mainCam.cameraTarget - mainCam.cameraPos, mainCam.up)) * cameraSpeed;
}