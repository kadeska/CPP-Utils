#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <glad/glad.h>
#include "shader.hpp"

struct RenderData
{
    unsigned int shaderProgram;
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
    Shader ourShader = Shader("shaders/vertex.glsl", "shaders/fragment.glsl");
};

RenderData genShaderProgram();

#endif