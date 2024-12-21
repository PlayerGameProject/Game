#pragma once

#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>
#include <filesystem>
#include <string>

#include <glad/glad.h>
#include <stb/stb_image.h>

#include "../Shader/Shader.h"

class Texture
{
public:
	GLuint textureID;
	GLenum type;
	GLuint* textures;

	Texture() = default;
	Texture(std::string texture, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType);
	GLuint* Initialize(std::string texturePath[], GLsizei textureCount, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType);
	void TextureUnit(Shader& Shader, const char* uniform, GLuint unit);
	void Bind();
	void Unbind();
	~Texture();
	
private:
	void LoadTexture(const char* texture, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType);
};

#endif
