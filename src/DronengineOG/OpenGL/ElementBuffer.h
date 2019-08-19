#pragma once
#include "../Core.h"

namespace DronengineOG {
	class ElementArray
	{
	public:
		ElementArray();
		~ElementArray();

		void Bind(unsigned int* indices);
		void UnBind();

	private:
		unsigned int bufferID;
	};
}