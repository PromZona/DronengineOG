#include "Application.h"
#include "Renderer.h"
#include "ObjectHandler.h"

namespace DronengineOG {

	Application::Application()
	{
		is_running = true;
		OpenGLHandler = NULL;
	}

	Application::~Application()
	{

	}

	void Application::initOpenGLHandler(int windowWidth, int windowHeight, const char* windowName)
	{
		this->OpenGLHandler = new Initialization();
		this->OpenGLHandler->init(windowWidth, windowHeight, windowName);
	}

	void Application::Run()
	{
		Renderer* render = new Renderer(this->OpenGLHandler);
		ObjectHandler* ObjHandler = new ObjectHandler();

		while (is_running)
		{
			ObjHandler->Update();
			render->Update();
		}

		delete render;
		delete ObjHandler;
	}
}