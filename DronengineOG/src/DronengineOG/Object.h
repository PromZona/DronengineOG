#pragma once
#include <vector>
#include "Core.h"
namespace DronengineOG {
	class Object
	{
	public:
		Object();
		~Object();

		void SetVertices(std::vector<float>& v);
		void SetIndices(std::vector<unsigned int>& i);
		std::vector<float> GetVertices();
		std::vector<unsigned int> GetIndices();
	private:
		std::vector<float> vertices;
		std::vector<unsigned int> indices;
	};
}