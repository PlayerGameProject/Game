#pragma once

#ifndef VAO_H
#define VAO_H

#include <glad/glad.h>

#include "../Shader/VBO.h"

class VAO
{
public:
	GLuint vaoID;

	VAO();
	void LinkAttributes(VBO& VBO, GLuint layout, GLint numberOfComponents, GLenum type, GLsizei stride, const void* offset);
	void Bind();
	void Unbind();
	~VAO();
};

#endif
