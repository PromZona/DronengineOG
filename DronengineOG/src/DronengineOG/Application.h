#pragma once
#include "initialization.h"
#include "Renderer.h"
#include "ObjectHandler.h"

namespace DronengineOG {

	class Application
	{
	public:
		Application();
		virtual ~Application();
		virtual void Run();
		virtual void UserUpdate();
		virtual void UserStart(ObjectHandler* h);
		void initOpenGLHandler(int windowWidth, int windowHeight, const char* windowName);
	protected:
		bool is_running;
		Initialization* OpenGLHandler;
		Renderer* render;
		ObjectHandler* ObjHandler;
	};

	Application* CreateApplication();
}
