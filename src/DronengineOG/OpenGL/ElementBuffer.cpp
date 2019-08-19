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

	void ElementArray::Bind(unsigned int* indices)
	{
		unsigned int indicesX[] = {  // note that we start from 0!
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		};
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->bufferID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indicesX), indicesX, GL_STATIC_DRAW);
	}

	void ElementArray::UnBind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	}
}