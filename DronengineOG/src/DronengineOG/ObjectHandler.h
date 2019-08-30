#pragma once
#include "Core.h"
#include "Object.h"

namespace DronengineOG
{
	class ObjectHandler
	{
	public:
		ObjectHandler();
		~ObjectHandler();
		static void Update();
		static void AddObject(Object* obj);
		static void DeleteObject(Object* obj);
	private:
		static std::vector<DronengineOG::Object*> ObjectsCollection;
	};

}