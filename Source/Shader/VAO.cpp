#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &vaoID);
}

void VAO::LinkAttributes(VBO& VBO, GLuint layout, GLint numberOfComponents, GLenum type, GLsizei stride, const void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, numberOfComponents, type, GL_FALSE, stride, offset);
	glEnableVertexAttribArray(layout);
	VBO.Unbind();
}

void VAO::Bind()
{
	glBindVertexArray(vaoID);
}

void VAO::Unbind()
{
	glBindVertexArray(0);
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &vaoID);
}
