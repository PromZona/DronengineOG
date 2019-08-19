#include "VertexArray.h"

namespace DronengineOG
{
	VertexArray::VertexArray()
	{
		this->arrayID = 0;
		glGenVertexArrays(1, &(this->arrayID));
	}

	VertexArray::~VertexArray()
	{

	}

	void VertexArray::Bind()
	{
		glBindVertexArray(this->arrayID);
	}

	void VertexArray::UnBind()
	{
		glBindVertexArray(0);
	}
}