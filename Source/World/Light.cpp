#include "Light.h"

GLfloat LightVertices[] =
{
    // Positions
    -1.0f,  1.0f,  1.0f,  // Front Face Top Left Vertex
     1.0f,  1.0f,  1.0f,  // Front Face Top Right Vertex
     1.0f, -1.0f,  1.0f,  // Front Face Bottom Right Vertex
    -1.0f, -1.0f,  1.0f,  // Front Face Bottom Left Vertex

    -1.0f,  1.0f, -1.0f,  // Right Face Top Left Vertex
    -1.0f,  1.0f,  1.0f,  // Right Face Top Right Vertex
    -1.0f, -1.0f,  1.0f,  // Right Face Bottom Right Vertex
    -1.0f, -1.0f, -1.0f,  // Right Face Bottom Left Vertex

     1.0f,  1.0f, -1.0f,  // Back Face Top Left Vertex
    -1.0f,  1.0f, -1.0f,  // Back Face Top Right Vertex
    -1.0f, -1.0f, -1.0f,  // Back Face Bottom Right Vertex
     1.0f, -1.0f, -1.0f,  // Back Face Bottom Left Vertex

     1.0f,  1.0f,  1.0f,  // Left Face Top Left Vertex
     1.0f,  1.0f, -1.0f,  // Left Face Top Right Vertex
     1.0f, -1.0f, -1.0f,  // Left Face Bottom Right Vertex

     1.0f, -1.0f,  1.0f,  // Left Face Bottom Left Vertex
    -1.0f,  1.0f, -1.0f,  // Top Face Top Left Vertex
     1.0f,  1.0f, -1.0f,  // Top Face Top Right Vertex
     1.0f,  1.0f,  1.0f,  // Top Face Bottom Right Vertex
    -1.0f,  1.0f,  1.0f,  // Top Face Bottom Left Vertex

    -1.0f, -1.0f,  1.0f,  // Bottom Face top Left Vertex
     1.0f, -1.0f,  1.0f,  // Bottom Face top Right Vertex
     1.0f, -1.0f, -1.0f,  // Bottom Face Bottom Right Vertex
    -1.0f, -1.0f, -1.0f   // Bottom Face Bottom Left Vertex
};

GLuint LightIndices[] =
{
    // Front Face
    0,  1,  3,
    1,  2,  3,
	
   // Right Face
    4,  5,  7,
    5,  6,  7,
	
   // Back Face
    8,  9, 11,
    9, 10, 11,
	
   // Left Face
   12, 13, 15,
   13, 14, 15,
	
   // Top Face
   16, 17, 19,
   17, 18, 19,
	
   // Bottom Face
   20, 21, 23,
   21, 22, 23
};

Light::Light() : Shader(ProjectDirectory "/Source/World/Light.vert", ProjectDirectory "/Source/World/Light.frag"), VAO(), VBO(LightVertices, sizeof(LightVertices)), EBO(LightIndices, sizeof(LightIndices))
{
	VAO.Bind();
	VBO.Bind();
	EBO.Bind();

	VAO.LinkAttributes(VBO, 0, 3, GL_FLOAT, 3 * sizeof(float), (void*)0);

	VAO.Unbind();
	VBO.Unbind();
	EBO.Unbind();
}

void Light::Render()
{
	Shader.Activate();
	VAO.Bind();
	glDrawElements(GL_TRIANGLES, sizeof(LightIndices) / sizeof(int), GL_UNSIGNED_INT, 0);
}
