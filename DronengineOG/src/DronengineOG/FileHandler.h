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
		static std::string FileToString(std::string path);
		void SetPath(std::string str);
	private:
		std::string path;
	};
}
