#pragma once
#include "Core.h"

namespace DronengineOG {

	class Texture {
	public:
		Texture();
		Texture(int w, int h, unsigned char** d);
		~Texture();
		void LoadData(unsigned char**);
		void Bind();
		void UnBind();

	private:
		int width, height;
		unsigned int textureID;
		unsigned char* Data;
	};
}