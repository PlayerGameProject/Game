#include "Shader.h"

std::string ReadFile(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);

	if (!file)
		throw std::runtime_error("Failed to open file: " + filename);

	std::stringstream buffer;
	buffer << file.rdbuf();
	
	return buffer.str();
}

Shader::Shader(const std::string& vertexSource, const std::string& fragmentSource)
{
	CompileAndLink(vertexSource.c_str(), fragmentSource.c_str());
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexSource = ReadFile(vertexFile);
	std::string fragmentSource = ReadFile(fragmentFile);

	CompileAndLink(vertexSource.c_str(), fragmentSource.c_str());
}

void Shader::Activate()
{
	glUseProgram(programID);
}

Shader::~Shader()
{
	glDeleteProgram(programID);
}

void Shader::CompileAndLink(const char* vertex, const char* fragment)
{
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex, NULL);
	glCompileShader(vertexShader);
	Error(vertexShader, "Vertex Shader");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment, NULL);
	glCompileShader(fragmentShader);
	Error(fragmentShader, "Fragment Shader");

	programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);
	Error(programID, "Shader Program");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Error(GLuint shader, const char* type)
{
	GLint compiled;
	char infoLog[1024];

	if (type != "Shader Program")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

		if (compiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
			throw std::runtime_error(std::string(type) + " compilation failed:\n" + infoLog);
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &compiled);

		if (compiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
			throw std::runtime_error(std::string(type) + " linking failed:\n" + infoLog);
		}
	}
}
