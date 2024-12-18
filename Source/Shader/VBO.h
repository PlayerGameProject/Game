#pragma once

#ifndef VBO_H
#define VBO_H

#include <glad/glad.h>

class VBO
{
public:
	GLuint vboID;

	VBO(GLfloat* vertices, GLsizeiptr size);
	void Bind();
	void Unbind();
	~VBO();
};

#endif
