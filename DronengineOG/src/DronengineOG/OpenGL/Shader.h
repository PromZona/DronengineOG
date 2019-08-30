#pragma once
#include "../Core.h"

#define DEFAULT_FRAGMENT_BUFFER "#version 330 core \n out vec4 FragColor;\n void main() { \n FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n}"
#define DEFAULT_VERTEX_BUFFER "#version 330 core \n layout(location = 0) in vec3 aPos;\n void main() { \n gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n}"

namespace DronengineOG {
	class Shader
	{
	public:
		Shader();
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