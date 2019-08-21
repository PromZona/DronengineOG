#include "FileHandler.h"

namespace DronengineOG{

	FileHandler::FileHandler()
	{

	}

	FileHandler::FileHandler(std::string path)
	{
		this->path = path;
	}

	FileHandler::~FileHandler()
	{

	}

	//if use instance of class
	std::string FileHandler::FileToString()
	{
		std::ifstream file;
		file.open(this->path, std::ios::in);
		if (!file.is_open())
		{
			std::cout << "Cannot open file - " << this->path << std::endl;
			return "error";
		}
		std::string output;
		std::string buffer;
		while (std::getline(file, buffer))
		{
			output += buffer;
		}
		file.close();
		return output;
	}

	//if ude only this function
	std::string FileHandler::FileToString(std::string str)
	{
		std::ifstream file;
		file.open(str, std::ios::in);
		if (!file.is_open())
		{
			std::cout << "Cannot open file - " << str << std::endl;
			return "error";
		}
		std::string output;
		std::string buffer;
		while (std::getline(file, buffer))
		{
			output += buffer;
			output += "\n";
		}
		file.close();
		return output;
	}

	void FileHandler::SetPath(std::string str)
	{
		this->path = str;
	}
}
