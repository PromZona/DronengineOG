#pragma once
#include "../Core.h"

namespace DronengineOG {
	class VertexArray
	{
	public:
		VertexArray();
		~VertexArray();

		void Bind();
		void UnBind();

	private:
		unsigned int arrayID;
	};
}