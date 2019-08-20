#pragma once
#include "Application.h"
#include "initialization.h"

namespace DronengineOG {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		virtual void Run();
		void initOpenGLHandler(int windowWidth, int windowHeight, const char* windowName);
	private:
		bool is_running;
		Initialization* OpenGLHandler;
	};

	Application* CreateApplication();
}
