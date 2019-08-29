#pragma once

#include "Core.h"
#include <string>
#include <fstream>

namespace DronengineOG {
	class FileHandler
	{
	public:
		FileHandler();
		FileHandler(std::string path);
		~FileHandler();
		std::string FileToString();
		void SetPath(std::string str);

		static std::string FileToString(std::string path);
		static unsigned char* ImageToData(std::string path, int* width, int* height, int* channels);
	private:
		std::string path;
	};
}
