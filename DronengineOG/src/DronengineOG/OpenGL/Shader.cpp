#include "Shader.h"

namespace DronengineOG {

	Shader::Shader(const GLchar** shader)
	{
		this->shader = *shader;
		this->shaderID = 0;
	}

	Shader::Shader(std::string* string)
	{
		this->shader = string->c_str();
		this->shaderID = 0;
	}

	Shader::~Shader()
	{
		Shader::DeleteProgram();
	}

	void Shader::CreateProgram(GLenum ShaderType)
	{
		this->shaderID = glCreateShader(ShaderType);
		std::cout << "Created new shaderID = " << shaderID << std::endl;
	}

	void Shader::DeleteProgram()
	{
		std::cout << "Delete shaderID = " << shaderID << std::endl;
		glDeleteShader(shaderID);
		shaderID = 0;
	}

	void Shader::Compile()
	{
		glShaderSource(this->shaderID, 1, &this->shader, NULL);
		glCompileShader(this->shaderID);
		int  success;
		char infoLog[512];

		glGetShaderiv(this->shaderID, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(this->shaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
		}
	}

	int Shader::GetShaderID()
	{
		return this->shaderID;
	}

	int CreateShaderProgram(Shader* vertex, Shader* fragment)
	{
		vertex->CreateProgram(GL_VERTEX_SHADER);
		fragment->CreateProgram(GL_FRAGMENT_SHADER);
		vertex->Compile();
		fragment->Compile();
		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();
		std::cout << "Shader program created =" << shaderProgram << std::endl;
		glAttachShader(shaderProgram, vertex->GetShaderID());
		glAttachShader(shaderProgram, fragment->GetShaderID());
		glLinkProgram(shaderProgram);

		vertex->DeleteProgram();
		fragment->DeleteProgram();

		return shaderProgram;
	}

	int CreateShaderProgram(const GLchar** vertexS, const GLchar** fragmentS)
	{
		int success = 0;
		char infoLog[512];
		Shader* vertex = new Shader(vertexS);
		Shader* fragment = new Shader(fragmentS);

		vertex->CreateProgram(GL_VERTEX_SHADER);
		fragment->CreateProgram(GL_FRAGMENT_SHADER);
		vertex->Compile();
		fragment->Compile();
		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();
		std::cout << "Shader program created =" << shaderProgram << std::endl;
		glAttachShader(shaderProgram, vertex->GetShaderID());
		glAttachShader(shaderProgram, fragment->GetShaderID());
		glLinkProgram(shaderProgram);

		//error check
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		delete vertex;
		delete fragment;

		return shaderProgram;
	}

	int CreateShaderProgram(std::string vertexS, std::string fragmentS)
	{
		int success = 0;
		char infoLog[512];
		Shader* vertex = new Shader(&vertexS);
		Shader* fragment = new Shader(&fragmentS);

		vertex->CreateProgram(GL_VERTEX_SHADER);
		fragment->CreateProgram(GL_FRAGMENT_SHADER);
		vertex->Compile();
		fragment->Compile();
		unsigned int shaderProgram;
		shaderProgram = glCreateProgram();
		std::cout << "Shader program created =" << shaderProgram << std::endl;
		glAttachShader(shaderProgram, vertex->GetShaderID());
		glAttachShader(shaderProgram, fragment->GetShaderID());
		glLinkProgram(shaderProgram);

		//error check
		glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
		if (!success) {
			glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
		}

		delete vertex;
		delete fragment;

		return shaderProgram;
	}
}