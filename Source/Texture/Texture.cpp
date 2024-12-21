#include "Texture.h"

Texture::Texture(std::string image, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType) : type(textureType)
{
	int imageWidth;
	int imageHeight;
	int colorChannels;

	stbi_set_flip_vertically_on_load(true);

	unsigned char* bytes = stbi_load(image.c_str(), &imageWidth, &imageHeight, &colorChannels, 0);

	glGenTextures(1, &textureID);
	glActiveTexture(slot);
	glBindTexture(textureType, textureID);

	glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
	glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_REPEAT);

	glTexImage2D(textureType, 0, GL_RGBA, imageWidth, imageHeight, 0, format, pixelType, bytes);
	glGenerateMipmap(textureType);

	stbi_image_free(bytes);

	glBindTexture(textureType, 0);
}

GLuint* Texture::Initialize(std::string texturePath[], GLsizei textureCount, GLenum textureType, GLenum slot, GLenum format, GLenum pixelType)
{
	this->type = textureType;
	this->textures = new GLuint[textureCount];
	glGenTextures(textureCount, textures);

	for (int i = 0; i < textureCount; i++)
	{
		int imageWidth;
		int imageHeight;
		int colorChannels;

		stbi_set_flip_vertically_on_load(true);

		unsigned char* bytes = stbi_load((texturePath[i]).c_str(), &imageWidth, &imageHeight, &colorChannels, 0);

		glActiveTexture(slot);
		glBindTexture(textureType, textures[i]);

		glTexParameteri(textureType, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_LINEAR);
		glTexParameteri(textureType, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTexParameteri(textureType, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(textureType, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTexImage2D(textureType, 0, GL_RGBA, imageWidth, imageHeight, 0, format, pixelType, bytes);
		glGenerateMipmap(textureType);

		stbi_image_free(bytes);

		glBindTexture(textureType, 0);
	}

	this->textureID = *textures;
	return textures;
}

void Texture::TextureUnit(Shader& Shader, const char* uniform, GLuint unit)
{
	GLuint textureUniform = glGetUniformLocation(Shader.programID, uniform);
	Shader.Activate();
	glUniform1i(textureUniform, unit);
}

void Texture::Bind()
{
	glBindTexture(type, textureID);
}

void Texture::Unbind()
{
	glBindTexture(type, 0);
}

Texture::~Texture()
{
	glDeleteTextures(1, &textureID);
}
