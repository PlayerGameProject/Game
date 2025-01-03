#pragma once

#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>

#include "../Shader/Shader.h"
#include "../Shader/VAO.h"
#include "../Shader/VBO.h"
#include "../Shader/EBO.h"
#include "../Texture/Texture.h"

class Mesh
{
public:
    Shader Shader;
    VAO VAO;
    VBO VBO;
    EBO EBO;
    Texture Texture;
    GLuint* Textures;
    
    Mesh();
    void Render();
    ~Mesh() = default;
};

#endif
