#pragma once
#include "customLogging.hpp"
#include "glm/glm.hpp"
#include <glm/gtc/matrix_transform.hpp>
#include <GLFW/glfw3.h>

class Camera
{
public:
    Camera();
    glm::mat4 view;
    glm::vec3 cameraPos;
    glm::vec3 cameraFront;
    glm::vec3 up;
    glm::vec3 cameraTarget;
    glm::vec3 cameraRight;

    void updateView();
    void dostuff();
};