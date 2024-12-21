#pragma once

#ifndef LIGHT_H
#define LIGHT_H

#include <glad/glad.h>

#include "../Shader/Shader.h"
#include "../Shader/VAO.h"
#include "../Shader/VBO.h"
#include "../Shader/EBO.h"

class Light
{
public:
    Shader Shader;
    VAO VAO;
    VBO VBO;
    EBO EBO;
    
    Light();
    void Render();
    ~Light() = default;
};

#endif
