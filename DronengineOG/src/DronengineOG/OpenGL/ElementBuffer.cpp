#include "ElementBuffer.h"

namespace DronengineOG
{
	ElementArray::ElementArray()
	{
		glGenBuffers(1, &(this->bufferID));
	}

	ElementArray::~ElementArray()
	{

	}

	void ElementArray::Bind(Object* obj)
	{

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->bufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, obj->GetIndices().size() * sizeof(int), &obj->GetIndices()[0], GL_STATIC_DRAW);
	}

	void ElementArray::UnBind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}