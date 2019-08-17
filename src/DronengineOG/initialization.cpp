#include "initialization.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace DronengineOG
{
	Initialization::Initialization()
	{
		window = NULL;
	}

	Initialization::~Initialization()
	{

	}

	void Initialization::init(int windowWidth, int windowHeight, const char* windowName)
	{		
		if (!glfwInit())
			return;

		window = glfwCreateWindow(windowWidth, windowHeight, windowName, NULL, NULL);
		if (!window)
		{
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(window);

		int version = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		std::cout << version << std::endl;
		glViewport(0, 0, windowWidth, windowHeight);
	}

}