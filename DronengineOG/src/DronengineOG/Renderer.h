#pragma once
#include "Core.h"
#include "initialization.h"
#include "Object.h"
#include "OpenGL/Shader.h"
#include "OpenGL/VertexArray.h"
#include "OpenGL/VertexBuffer.h"
#include "OpenGL/ElementBuffer.h"

namespace DronengineOG {
	class Renderer
	{
	public:
		Renderer(Initialization* OpenGLinit);
		~Renderer();

		void Update();

	private:
		int shader;
		Initialization* OpenGLinit;
		VertexArray* VAO;
		VertexBuffer* BAO;
		ElementArray* EAO;
	};
}