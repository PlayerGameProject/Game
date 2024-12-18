#include "Mesh.h"

GLfloat vertices[] =
{
    // Positions         // Colors
     0.0f,  0.5f, 0.0f,  1.0f, 0.0f, 0.0f,  // Top Vertex
     0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,  // Bottom Right Vertex
    -0.5f, -0.5f, 0.0f,  0.0f, 0.0f, 1.0f   // Bottom Left Vertex
};

GLuint indices[] =
{   // Triangle
    0, 1, 2
};

Mesh::Mesh() : Shader(ProjectDirectory "/Source/World/Mesh.vert", ProjectDirectory "/Source/World/Mesh.frag"), VAO(), VBO(vertices, sizeof(vertices)), EBO(indices, sizeof(indices))
{
    VAO.Bind();
    VBO.Bind();
    EBO.Bind();

    VAO.LinkAttributes(VBO, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    VAO.LinkAttributes(VBO, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));

    VAO.Unbind();
    VBO.Unbind();
    EBO.Unbind();

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
}

void Mesh::Render()
{
    Shader.Activate();
    VAO.Bind();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
}

Mesh::~Mesh()
{
    VAO.~VAO();
    VBO.~VBO();
    EBO.~EBO();
    Shader.~Shader();
}
