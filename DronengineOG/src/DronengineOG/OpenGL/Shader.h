#pragma once
#include "../Core.h"

namespace DronengineOG {
	class Shader
	{
	public:
		Shader(const GLchar** shader);
		Shader(std::string* string);
		~Shader();

		void CreateProgram(GLenum ShaderType);
		void DeleteProgram();
		void Compile();
		int GetShaderID();
		void setUniformBool(const std::string& name, bool value);
		void setUniformInt(const std::string& name, int value);
		void setUniformFloat(const std::string& name, float value);
	private:
		const GLchar* shader;
		unsigned int shaderID;
	};

	int CreateShaderProgram(Shader* vertex, Shader* fragment);
	int CreateShaderProgram(const GLchar** vertex, const GLchar** fragment);
	int CreateShaderProgram(std::string vertex, std::string fragment);
}