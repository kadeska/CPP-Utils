#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "3rdparty/glad/glad.h"
#include "3rdparty/glfw/glfw3.h"
#include <string>

extern GLFWwindow *window;

int initialize();
GLFWwindow *createWindow(int width, int height, std::string name);
void framebuffer_size_callback(GLFWwindow *window, int width, int height);
void processInput(GLFWwindow *window);

#endif // WINDOW_HPP