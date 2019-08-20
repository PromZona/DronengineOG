#pragma once
#include "../Core.h"
#include "../Object.h"

namespace DronengineOG {
	class VertexBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		void Bind();
		void Bind(Object* obj);
		void UnBind();

	private:
		unsigned int bufferID;
	};
}