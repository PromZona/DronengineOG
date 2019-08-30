#pragma once
#include <vector>
#include "Core.h"
#include "OpenGL/Shader.h"

namespace DronengineOG {
	class Object
	{
	public:
		Object();
		~Object();

		void SetVertices(std::vector<float>& v);
		void SetIndices(std::vector<unsigned int>& i);
		std::vector<float> GetVertices();
		std::vector<unsigned int> GetIndices();
		void SetVertexShader(const GLchar** shader);
		void SetVertexShader(std::string* string);
		void SetFragmentShader(const GLchar** shader);
		void SetFragmentShader(std::string* string);
		int GetShaderID();
		void SetShaderID(unsigned int shaderid);
		Shader* GetVertexShader();
		Shader* GetFragmentShader();
		virtual void Update();
	private:
		unsigned int shaderID;
		Shader* vertexShader; 
		Shader* fragmentShader;
		std::vector<float> vertices;
		std::vector<unsigned int> indices;
	};
}