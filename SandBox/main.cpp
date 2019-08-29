#include "DOG.h"

class SandBox : public DronengineOG::Application
{
public:
	SandBox() 
	{
		initOpenGLHandler(800, 600, "Some");
	}

	~SandBox()
	{

	}
};

class MyObject : public DronengineOG::Object
{
public:
	MyObject()
	{

	}
	~MyObject()
	{

	}
};

DronengineOG::Application* DronengineOG::CreateApplication()
{
	return new SandBox();
}