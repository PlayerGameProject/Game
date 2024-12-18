#pragma once

#ifndef EBO_H
#define EBO_H

#include <glad/glad.h>

class EBO
{
public:
	GLuint eboID;

	EBO(GLuint* indices, GLsizeiptr size);
	void Bind();
	void Unbind();
	~EBO();
};

#endif
