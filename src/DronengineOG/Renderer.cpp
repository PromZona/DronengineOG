#include "Renderer.h"

namespace DronengineOG {

	Renderer::Renderer(Initialization* OpenGL)
	{
		shader = 0;
		this->OpenGLinit = OpenGL;
		VAO = new VertexArray();
		BAO = new VertexBuffer();
		EAO = new ElementArray();
		VAO->Bind();
		float vertices[] = {
			0.5f,  0.5f, 0.0f,  // top right
			0.5f, -0.5f, 0.0f,  // bottom right
			-0.5f, -0.5f, 0.0f,  // bottom left
			-0.5f,  0.5f, 0.0f   // top left 
		};
		unsigned int indices[] = {  // note that we start from 0!
			0, 1, 3,   // first triangle
			1, 2, 3    // second triangle
		};
		//BAO->Bind();
		BAO->Bind(vertices);
		EAO->Bind(indices);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
		glEnableVertexAttribArray(0);
		BAO->UnBind();
	}

	Renderer::~Renderer()
	{

	}

	void Renderer::Update()
	{
		if (shader == 0)
		{
			const GLchar* vertexShaderSourceCode[] = { "#version 330 core\n layout(location = 0) in vec3 aPos;\n void main(){\n gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n}" };
			const GLchar* fragmentShaderSourceCode[] = { "#version 330 core \n out vec4 FragColor; \n void main(){\n FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n}" };
			shader = CreateShaderProgram(vertexShaderSourceCode, fragmentShaderSourceCode);
		}
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shader);
		VAO->Bind();
		//glDrawArrays(GL_TRIANGLES, 0, 6);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(this->OpenGLinit->window);
		glfwPollEvents();
	}
}