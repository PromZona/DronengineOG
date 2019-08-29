#include "Texture.h"

namespace DronengineOG {

	Texture::Texture()
	{
		this->Data = { 0 };
		this->width = 0;
		this->height = 0;
		glGenTextures(1, &this->textureID);
	}

	Texture::Texture(int w, int h, unsigned char** d)
	{
		this->Data = *d;
		this->width = w;
		this->height = h;
		glGenTextures(1, &this->textureID);
	}

	Texture::~Texture()
	{

	}

	void Texture::LoadData(unsigned char** data)
	{
		this->Data = *data;
	}

	void Texture::Bind()
	{
		glBindTexture(GL_TEXTURE_2D, this->textureID);
	}

}