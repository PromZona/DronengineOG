#pragma once
#include "../Core.h"
#include "../Object.h"

namespace DronengineOG {
	class ElementArray
	{
	public:
		ElementArray();
		~ElementArray();

		void Bind(Object* obj);
		void UnBind();

	private:
		unsigned int bufferID;
	};
}