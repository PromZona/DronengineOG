#include "DOG.h"
#include "DronengineOG/ObjectHandler.h"
#include "DronengineOG/Object.h"
#include "DronengineOG/FileHandler.h"

class MyObject : public DronengineOG::Object
{
public:
	MyObject()
	{

	}
	~MyObject()
	{

	}

	void Update() override
	{
		std::vector<float> a = this->GetVertices();
		bool needtochange = false;
		for (int i = 0; i < a.size(); i = i+3)
		{	
			if (right)
			{
				a[i] += 0.001f;
				if (a[i] > 1.0f) needtochange = true;
			}
			else
			{
				a[i] -= 0.001f;
				if (a[i] < -1.0f) needtochange = true;
			}
		}
		if (needtochange) right = !right;
		this->SetVertices(a);
	}
	bool right = true;
};

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
	
	void UserStart(DronengineOG::ObjectHandler* h) override
	{
		// First Object
		std::vector<float> vertices = {
			0.8f,  0.8f, 0.0f,  // top right
			0.8f, 0.0f, 0.0f,  // bottom right
			0.5f, 0.0f, 0.0f,  // bottom left
			0.5f,  0.8f, 0.0f   // top left 
		};
		std::vector<unsigned int> indices = {  // note that we start from 0!
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		};
		MyObject* o = new MyObject();
		o->SetVertices(vertices);
		o->SetIndices(indices);
		v = DronengineOG::FileHandler::FileToString("vertex.glsl");
		f = DronengineOG::FileHandler::FileToString("fragment.glsl");
		o->SetVertexShader(&v);
		o->SetFragmentShader(&f);
		h->AddObject(o);

		// Second Object
		std::vector<float> vertices1 = {
			-0.8f,  -0.8f, 0.0f,  // top right
			-0.8f, 0.0f, 0.0f,  // bottom right
			-0.5f, 0.0f, 0.0f,  // bottom left
			-0.5f,  -0.8f, 0.0f   // top left 
		};
		std::vector<unsigned int> indices1 = {  // note that we start from 0!
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		};
		MyObject* o1 = new MyObject();
		o1->SetVertices(vertices1);
		o1->SetIndices(indices1);
		o1->SetVertexShader(&v);
		o1->SetFragmentShader(&f);
		h->AddObject(o1);
	}

	void UserUpdate() override
	{
		
	}

	std::string v;
	std::string f;

};


DronengineOG::Application* DronengineOG::CreateApplication()
{
	return new SandBox();
}
