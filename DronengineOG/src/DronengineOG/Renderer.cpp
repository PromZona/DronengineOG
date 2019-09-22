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
			std::string vertexShader = FileHandler::FileToString("vertex.glsl");
			std::string fragmentShader = FileHandler::FileToString("fragment.glsl");
			shader = CreateShaderProgram(vertexShader, fragmentShader);
		}
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(shader);
		VAO->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(this->OpenGLinit->window);
		glfwPollEvents();
	}

	void Renderer::Draw(std::vector<Object*> collection)
	{
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		for (int i = 0; i < collection.size(); i++)
		{
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
			glEnableVertexAttribArray(0);
			BAO->UnBind();
			BAO->Bind(collection[i]);
			EAO->Bind(collection[i]);
			if (collection[i]->GetShaderID() == 0)
			{
				collection[i]->SetShaderID(CreateShaderProgram(collection[i]->GetVertexShader(), collection[i]->GetFragmentShader()));
			}
			glUseProgram(collection[i]->GetShaderID());
			VAO->Bind(); // TODO: Дописать рендер. Разобраться с BAO, EAO и Подключением атрибутов
			glDrawElements(GL_TRIANGLES, collection[i]->GetIndices().size(), GL_UNSIGNED_INT, 0);
		}
		glfwSwapBuffers(this->OpenGLinit->window);
		glfwPollEvents();
	}
}