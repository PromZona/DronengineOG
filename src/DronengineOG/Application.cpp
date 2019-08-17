#include "Application.h"

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
		while (is_running)
		{
			
		}
	}
}