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
		float vertices[] = {
		-0.5f, -0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		0.0f,  0.5f, 0.0f
		};
		glBindBuffer(GL_ARRAY_BUFFER, this->bufferID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	}

	//Bind by array of vertices
	void VertexBuffer::Bind(float vertices[])
	{
		float verticesX[] = {
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left 
		};
		glBindBuffer(GL_ARRAY_BUFFER, this->bufferID);
		glBufferData(GL_ARRAY_BUFFER, sizeof(verticesX), verticesX, GL_STATIC_DRAW);
	}

	void VertexBuffer::UnBind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}