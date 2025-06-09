#include "camera.hpp"

glm::vec3 cameraPos;
glm::vec3 cameraFront;
glm::vec3 cameraUp;
glm::vec3 cameraDirection;
glm::vec3 cameraTarget;
Camera::Camera()
    : cameraPos(0.0f, 0.0f, 3.0f),
      cameraTarget(0.0f, 0.0f, 0.0f),
      up(0.0f, 1.0f, 0.0f)
{
    log("Camera constructor", CustomLogging::LogLevel::DEBUG);
    cameraDirection = glm::normalize(cameraPos - cameraTarget);
    cameraRight = glm::normalize(glm::cross(up, cameraDirection));
    // cameraUp = glm::cross(cameraDirection, cameraRight);
    // view = glm::lookAt(cameraPos, cameraTarget, up);
    glm::vec3 cameraPos = glm::vec3(0.0f, 0.0f, 3.0f);
    glm::vec3 cameraFront = glm::vec3(0.0f, 0.0f, -1.0f);
    glm::vec3 cameraUp = glm::vec3(0.0f, 1.0f, 0.0f);
    view = glm::lookAt(cameraPos, cameraPos + cameraFront, cameraUp);
}

void Camera::dostuff()
{
    log("Camera dostuff", CustomLogging::LogLevel::DEBUG);
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
