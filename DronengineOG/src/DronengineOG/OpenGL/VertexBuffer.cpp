#include "VertexBuffer.h"

namespace DronengineOG
{
	VertexBuffer::VertexBuffer()
	{
		glGenBuffers(1, &(this->bufferID));
	}

	VertexBuffer::~VertexBuffer()
	{

	}

	//Bind default triangle
	void VertexBuffer::Bind()
	{
		std::vector<float> vertices = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
		};
		glBindBuffer(GL_ARRAY_BUFFER, this->bufferID);
		glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), &vertices[0], GL_STATIC_DRAW);
	}

	//Bind by array of vertices
	void VertexBuffer::Bind(Object* obj)
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->bufferID);
		glBufferData(GL_ARRAY_BUFFER, obj->GetVertices().size() * sizeof(float), &obj->GetVertices()[0], GL_STATIC_DRAW);
	}

	void VertexBuffer::UnBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}