#ifndef PROGRAM_HPP
#define PROGRAM_HPP

#include <glad/glad.h>

struct RenderData {
    unsigned int shaderProgram;
    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;
};

RenderData genShaderProgram();

#endif