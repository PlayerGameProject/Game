#include "Mesh.h"

#include "glm/ext/matrix_transform.hpp"

GLfloat vertices[] =
{
	// Positions          // Colors          // Textures   // Normals
	-1.0f,  1.0f,  1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 1.0f,   0.0f,  0.0f,  1.0f,  // Front Face Top Left Vertex
	 1.0f,  1.0f,  1.0f,  1.0f, 1.0f, 1.0f,  1.0f, 1.0f,   0.0f,  0.0f,  1.0f,  // Front Face Top Right Vertex
	 1.0f, -1.0f,  1.0f,  0.0f, 1.0f, 0.0f,  1.0f, 0.0f,   0.0f,  0.0f,  1.0f,  // Front Face Bottom Right Vertex
	-1.0f, -1.0f,  1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 0.0f,   0.0f,  0.0f,  1.0f,  // Front Face Bottom Left Vertex
	 			   
	-1.0f,  1.0f, -1.0f,  1.0f, 0.0f, 1.0f,  0.0f, 1.0f,  -1.0f,  0.0f,  0.0f,  // Right Face Top Left Vertex
	-1.0f,  1.0f,  1.0f,  0.0f, 0.0f, 1.0f,  1.0f, 1.0f,  -1.0f,  0.0f,  0.0f,  // Right Face Top Right Vertex
	-1.0f, -1.0f,  1.0f,  0.0f, 1.0f, 1.0f,  1.0f, 0.0f,  -1.0f,  0.0f,  0.0f,  // Right Face Bottom Right Vertex
	-1.0f, -1.0f, -1.0f,  0.0f, 0.0f, 0.0f,  0.0f, 0.0f,  -1.0f,  0.0f,  0.0f,  // Right Face Bottom Left Vertex
	 			   
	 1.0f,  1.0f, -1.0f,  1.0f, 0.0f, 0.0f,  0.0f, 1.0f,   0.0f,  0.0f, -1.0f,  // Back Face Top Left Vertex
	-1.0f,  1.0f, -1.0f,  1.0f, 0.0f, 1.0f,  1.0f, 1.0f,   0.0f,  0.0f, -1.0f,  // Back Face Top Right Vertex
	-1.0f, -1.0f, -1.0f,  0.0f, 0.0f, 0.0f,  1.0f, 0.0f,   0.0f,  0.0f, -1.0f,  // Back Face Bottom Right Vertex
	 1.0f, -1.0f, -1.0f,  1.0f, 1.0f, 0.0f,  0.0f, 0.0f,   0.0f,  0.0f, -1.0f,  // Back Face Bottom Left Vertex
	 			   
	 1.0f,  1.0f,  1.0f,  1.0f, 1.0f, 1.0f,  0.0f, 1.0f,   1.0f,  0.0f,  0.0f,  // Left Face Top Left Vertex
	 1.0f,  1.0f, -1.0f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,   1.0f,  0.0f,  0.0f,  // Left Face Top Right Vertex
	 1.0f, -1.0f, -1.0f,  1.0f, 1.0f, 0.0f,  1.0f, 0.0f,   1.0f,  0.0f,  0.0f,  // Left Face Bottom Right Vertex
	 1.0f, -1.0f,  1.0f,  0.0f, 1.0f, 0.0f,  0.0f, 0.0f,   1.0f,  0.0f,  0.0f,  // Left Face Bottom Left Vertex
	 			   
	-1.0f,  1.0f, -1.0f,  1.0f, 0.0f, 1.0f,  0.0f, 1.0f,   0.0f,  1.0f,  0.0f,  // Top Face Top Left Vertex
	 1.0f,  1.0f, -1.0f,  1.0f, 0.0f, 0.0f,  1.0f, 1.0f,   0.0f,  1.0f,  0.0f,  // Top Face Top Right Vertex
	 1.0f,  1.0f,  1.0f,  1.0f, 1.0f, 1.0f,  1.0f, 0.0f,   0.0f,  1.0f,  0.0f,  // Top Face Bottom Right Vertex
	-1.0f,  1.0f,  1.0f,  0.0f, 0.0f, 1.0f,  0.0f, 0.0f,   0.0f,  1.0f,  0.0f,  // Top Face Bottom Left Vertex
	 			   
	-1.0f, -1.0f,  1.0f,  0.0f, 1.0f, 1.0f,  0.0f, 1.0f,   0.0f, -1.0f,  0.0f,  // Bottom Face top Left Vertex
	 1.0f, -1.0f,  1.0f,  0.0f, 1.0f, 0.0f,  1.0f, 1.0f,   0.0f, -1.0f,  0.0f,  // Bottom Face top Right Vertex
	 1.0f, -1.0f, -1.0f,  1.0f, 1.0f, 0.0f,  1.0f, 0.0f,   0.0f, -1.0f,  0.0f,  // Bottom Face Bottom Right Vertex
	-1.0f, -1.0f, -1.0f,  0.0f, 0.0f, 0.0f,  0.0f, 0.0f,   0.0f, -1.0f,  0.0f   // Bottom Face Bottom Left Vertex
};

GLuint indices[] =
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

std::string texture[] =
{
	// Face: Front, Right, Back, Left, Top, Bottom
	ProjectDirectory "/Resource/Texture/Grass Block Side.png",
	ProjectDirectory "/Resource/Texture/Grass Block Side.png",
	ProjectDirectory "/Resource/Texture/Grass Block Side.png",
	ProjectDirectory "/Resource/Texture/Grass Block Side.png",
	ProjectDirectory "/Resource/Texture/Grass Block Top.png",
	ProjectDirectory "/Resource/Texture/Grass Block Bottom.png"
};

glm::vec3 position[] =
{
    glm::vec3(0.0f, 0.0f, 0.0f)
};

Mesh::Mesh()
: Shader(ProjectDirectory "/Source/World/Mesh.vert", ProjectDirectory "/Source/World/Mesh.frag"), VAO(), VBO(vertices, sizeof(vertices)), EBO(indices, sizeof(indices))//, Texture(ProjectDirectory "/Resource/Texture/Texture.png", GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE)
{
    VAO.Bind();
    VBO.Bind();
    EBO.Bind();

    VAO.LinkAttributes(VBO, 0, 3, GL_FLOAT, 11 * sizeof(float), (void*)0);
    VAO.LinkAttributes(VBO, 1, 3, GL_FLOAT, 11 * sizeof(float), (void*)(3 * sizeof(float)));
    VAO.LinkAttributes(VBO, 2, 2, GL_FLOAT, 11 * sizeof(float), (void*)(6 * sizeof(float)));
    VAO.LinkAttributes(VBO, 3, 3, GL_FLOAT, 11 * sizeof(float), (void*)(8 * sizeof(float)));

    VAO.Unbind();
    VBO.Unbind();
    EBO.Unbind();

	Textures = Texture.Initialize(texture, 6, GL_TEXTURE_2D, GL_TEXTURE0, GL_RGBA, GL_UNSIGNED_BYTE);
    Texture.TextureUnit(Shader, "Texture", 0);

    glFrontFace(GL_CW);
    glCullFace(GL_BACK);
    glEnable(GL_CULL_FACE);
}

void Mesh::Render()
{
    Shader.Activate();
    Texture.Bind();
    VAO.Bind();

	for (int i = 0; i < sizeof(texture); i++)
	{
		glBindTexture(GL_TEXTURE_2D, Textures[i]);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (void*)(i * 6 * sizeof(unsigned int)));
	}
}
