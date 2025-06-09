#include "camera.hpp"

glm::vec3 cameraPos;
glm::vec3 cameraFront;
glm::vec3 cameraUp;
glm::vec3 cameraDirection;
glm::vec3 cameraTarget;
Camera::Camera()
    : cameraPos(0.0f, 10.0f, 10.0f),   // Higher and back
      cameraFront(0.0f, -1.0f, -1.0f), // Looking down and forward
      up(0.0f, 1.0f, 0.0f)
{
    cameraFront = glm::normalize(cameraFront);
    cameraTarget = cameraPos + cameraFront;
    cameraRight = glm::normalize(glm::cross(up, cameraFront));
    updateView();
}

void Camera::updateView()
{
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, up);
}

void Camera::dostuff()
{
    log("Camera dostuff", CustomLogging::LogLevel::DEBUG);
    const float radius = 10.0f;
    float camX = sin(glfwGetTime()) * radius;
    float camZ = cos(glfwGetTime()) * radius;
    cameraPos = glm::vec3(camX, 0.0, camZ);
    cameraTarget = glm::vec3(0.0, 0.0, 0.0);
    view = glm::lookAt(cameraPos, cameraTarget, up);
}
