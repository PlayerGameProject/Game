#include "Shader.h"

std::string ReadFile(const char* filename)
{
	std::ifstream file(filename, std::ios::binary);

	if (file)
	{
		std::string content;
		file.seekg(0, std::ios::end);
		content.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		file.read(&content[0], content.size());
		file.close();

		return content;
	}

	throw errno;
}

std::string ReadFile(std::string filename)
{
	std::ifstream file(filename.c_str(), std::ios::binary);

	if (file)
	{
		std::string content;
		file.seekg(0, std::ios::end);
		content.resize(file.tellg());
		file.seekg(0, std::ios::beg);
		file.read(&content[0], content.size());
		file.close();

		return content;
	}

	throw errno;
}

Shader::Shader(std::string vertexSource, std::string fragmentSource)
{
	const char* vertex = vertexSource.c_str();
	const char* fragment = fragmentSource.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex, NULL);
	glCompileShader(vertexShader);
	CompileError(vertexShader, "Vertex Shader");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment, NULL);
	glCompileShader(fragmentShader);
	CompileError(fragmentShader, "Fragment Shader");

	programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);
	CompileError(programID, "Shader Program");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile)
{
	std::string vertexSource = ReadFile(vertexFile);
	std::string fragmentSource = ReadFile(fragmentFile);

	const char* vertex = vertexSource.c_str();
	const char* fragment = fragmentSource.c_str();

	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertex, NULL);
	glCompileShader(vertexShader);
	CompileError(vertexShader, "Vertex Shader");

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragment, NULL);
	glCompileShader(fragmentShader);
	CompileError(fragmentShader, "Fragment Shader");

	programID = glCreateProgram();
	glAttachShader(programID, vertexShader);
	glAttachShader(programID, fragmentShader);
	glLinkProgram(programID);
	CompileError(programID, "Shader Program");

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
}

void Shader::Activate()
{
	glUseProgram(programID);
}

Shader::~Shader()
{
	glDeleteProgram(programID);
}

void Shader::CompileError(GLuint shader, const char* type)
{
	GLint compiled;
	char infoLog[1024];

	if (type != "Shader Program")
	{
		glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

		if (compiled == GL_FALSE)
		{
			glGetShaderInfoLog(shader, 1024, NULL, infoLog);
			std::cout << type << " Compilation Failed" << "\n" << infoLog << std::endl;
		}
	}
	else
	{
		glGetProgramiv(shader, GL_LINK_STATUS, &compiled);

		if (compiled == GL_FALSE)
		{
			glGetProgramInfoLog(shader, 1024, NULL, infoLog);
			std::cout << type << " Linking Failed" << "\n" << infoLog << std::endl;
		}
	}
}
