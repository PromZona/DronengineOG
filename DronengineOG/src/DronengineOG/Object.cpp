#include "Object.h"

namespace DronengineOG {

	Object::Object()
	{

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

}