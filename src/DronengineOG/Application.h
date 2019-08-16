#pragma once

namespace DronengineOG {

	class Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};
	Application* CreateApplication();
}
