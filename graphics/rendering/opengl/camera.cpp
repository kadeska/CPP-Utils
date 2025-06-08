#include "camera.hpp"

camera::camera()
    : cameraPos(0.0f, 0.0f, 3.0f),
      cameraTarget(0.0f, 0.0f, 0.0f),
      up(0.0f, 1.0f, 0.0f)
{
    log("camera constructor", CustomLogging::LogLevel::DEBUG);
    cameraDirection = glm::normalize(cameraPos - cameraTarget);
    cameraRight = glm::normalize(glm::cross(up, cameraDirection));
    cameraUp = glm::cross(cameraDirection, cameraRight);
    // view = glm::lookAt(cameraPos, cameraTarget, up);
    view = glm::lookAt(glm::vec3(0.0f, 0.0f, 3.0f),
                       glm::vec3(0.0f, 0.0f, 0.0f),
                       glm::vec3(0.0f, 1.0f, 0.0f));
}

void camera::dostuff()
{
    log("camera dostuff", CustomLogging::LogLevel::DEBUG);
    const float radius = 10.0f;
    float camX = sin(glfwGetTime()) * radius;
    float camZ = cos(glfwGetTime()) * radius;
    // glm::mat4 view;
    view = glm::lookAt(glm::vec3(camX, 0.0, camZ),
                       glm::vec3(0.0, 0.0, 0.0),
                       glm::vec3(0.0, 1.0, 0.0));
    cameraPos = glm::vec3(camX, 0.0, camZ);
    view = glm::lookAt(cameraPos, cameraTarget, up);
}