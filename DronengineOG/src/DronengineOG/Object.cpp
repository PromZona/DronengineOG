#include "Object.h"

namespace DronengineOG {

	Object::Object()
	{
		vertexShader = new Shader();
		fragmentShader = new Shader();
		this->shaderID = 0;
	}

	Object::~Object()
	{

	}

	void Object::SetVertices(std::vector<float>& v)
	{
		this->vertices = v;
	}

	void Object::SetIndices(std::vector<unsigned int>& i)
	{
		this->indices = i;
	}

	std::vector<float> Object::GetVertices()
	{
		return this->vertices;
	}

	std::vector<unsigned int> Object::GetIndices()
	{
		return this->indices;
	}

	void Object::SetVertexShader(const GLchar** shader)
	{
		delete this->vertexShader;
		this->vertexShader = new Shader(shader);
	}

	void Object::SetVertexShader(std::string* string)
	{
		delete this->vertexShader;
		this->vertexShader = new Shader(string);
	}

	void Object::SetFragmentShader(const GLchar** shader)
	{
		delete this->fragmentShader;
		this->fragmentShader = new Shader(shader);
	}

	void Object::SetFragmentShader(std::string* string)
	{
		delete this->fragmentShader;
		this->fragmentShader = new Shader(string);
	}

	int Object::GetShaderID()
	{
		return this->shaderID;
	}

	void Object::SetShaderID(unsigned int shaderid)
	{
		this->shaderID = shaderid;
	}

	Shader* Object::GetVertexShader()
	{
		return this->vertexShader;
	}

	Shader* Object::GetFragmentShader()
	{
		return this->fragmentShader;
	}

}