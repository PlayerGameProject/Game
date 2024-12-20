#pragma once

#ifndef MESH_H
#define MESH_H

#include <glad/glad.h>
#include <glm/glm.hpp>

#include "../Shader/Shader.h"
#include "../Shader/VAO.h"
#include "../Shader/VBO.h"
#include "../Shader/EBO.h"
#include "../Texture/Texture.h"

extern glm::vec3 position[];
extern std::string texture[];

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
