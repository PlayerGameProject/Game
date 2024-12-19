#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <exception>
#include <cerrno>

#include <glad/glad.h>

std::string ReadFile(const std::string& filename);

class Shader
{
public:
	GLuint programID;

	Shader(const std::string& vertexSource, const std::string& fragmentSource);
	Shader(const char* vertexFile, const char* fragmentFile);
	void Activate();
	~Shader();

private:
	void CompileAndLink(const char* vertex, const char* fragment);
	void Error(GLuint shader, const char* type);
};

#endif
