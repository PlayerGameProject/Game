#pragma once

#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>

#include "../Shader/Shader.h"
#include "../Shader/VAO.h"
#include "../Shader/VBO.h"
#include "../Shader/EBO.h"

class Mesh
{
private:
    Shader Shader;
    VAO VAO;
    VBO VBO;
    EBO EBO;
    
public:
    Mesh();
    void Render();
    ~Mesh();
};

#endif
