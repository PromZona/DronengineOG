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

	void Application::UserUpdate()
	{

	}

	void Application::UserStart(ObjectHandler* h)
	{
		
	}

	void Application::Run()
	{
		render = new Renderer(this->OpenGLHandler);
		ObjHandler = new ObjectHandler();
		UserStart(ObjHandler);
		while (is_running)
		{
			UserUpdate();
			ObjHandler->Update();
			render->Draw(ObjHandler->ObjectsCollection);
		}

		delete render;
		delete ObjHandler;
	}
}