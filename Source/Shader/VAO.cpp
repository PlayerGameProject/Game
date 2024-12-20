#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &vaoID);
}

void VAO::LinkAttributes(VBO& VBO, GLuint layout, GLuint numberOfComponents, GLenum type, GLsizeiptr stride, const void* offset)
{
	VBO.Bind();
	glVertexAttribPointer(layout, static_cast<int>(numberOfComponents), type, GL_FALSE, static_cast<GLsizei>(stride), offset);
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
