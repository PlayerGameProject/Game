#pragma once

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <stdexcept>
#include <cerrno>

#include <glad/glad.h>

std::string ReadFile(const char* filename);
std::string ReadFile(std::string filename);

class Shader
{
public:
	GLuint programID;

	Shader(std::string vertexSource, std::string fragmentSource);
	Shader(const char* vertexFile, const char* fragmentFile);
	void Activate();
	~Shader();

private:
	void CompileError(GLuint shader, const char* type);
};

#endif
