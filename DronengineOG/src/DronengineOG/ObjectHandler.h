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
		void Update();
		void AddObject(Object* obj);
		void DeleteObject(Object* obj);
		std::vector<DronengineOG::Object*> ObjectsCollection;
	};

}