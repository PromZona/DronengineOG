#pragma once
#include"Core.h"

namespace DronengineOG
{
	class Initialization
	{
	public:
		Initialization();
		~Initialization();
		void init(int windowWidth, int windowHeight, const char* windowName);

		GLFWwindow* window;
	};
}