#include "initialization.h"
#include <GLAD/glad.h>
#include <GLFW/glfw3.h>

namespace DronengineOG
{
	Initialization::Initialization()
	{
		this->window = NULL;
	}

	Initialization::~Initialization()
	{

	}

	void sizeCallback(GLFWwindow* window, int width, int height)
	{
		glViewport(0, 0, width, height);
	}

	void Initialization::init(int windowWidth, int windowHeight, const char* windowName)
	{		
		if (!glfwInit())
			return;

		this->window = glfwCreateWindow(windowWidth, windowHeight, windowName, NULL, NULL);
		if (!this->window)
		{
			glfwTerminate();
			return;
		}

		glfwMakeContextCurrent(this->window);
		glfwSetFramebufferSizeCallback(this->window, sizeCallback);
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
		}
	}

}