#pragma once
#include "../Core.h"

namespace DronengineOG {
	class VertexBuffer
	{
	public:
		VertexBuffer();
		~VertexBuffer();

		void Bind();
		void UnBind();

	};
}