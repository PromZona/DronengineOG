#pragma once
#include "../Core.h"

namespace DronengineOG {
	class Shader
	{
	public:
		Shader(const GLchar** shader);
		~Shader();

		void CreateProgram(GLenum ShaderType);
		void DeleteProgram();
		void Compile();
		int GetShaderID();
	private:
		const GLchar** shader;
		unsigned int shaderID;
	};

	int CreateShaderProgram(Shader* vertex, Shader* fragment);
	int CreateShaderProgram(const GLchar** vertex, const GLchar** fragment);
}