#include "ObjectHandler.h"

namespace DronengineOG
{
	ObjectHandler::ObjectHandler()
	{

	}

	ObjectHandler::~ObjectHandler()
	{

	}

	void ObjectHandler::Update()
	{
		int objectsCount = this->ObjectsCollection.size();
		for (int i = 0; i < objectsCount; i++)
		{
			this->ObjectsCollection[i]->Update();
		}
	}

	void ObjectHandler::AddObject(Object* obj)
	{
		this->ObjectsCollection.push_back(obj);
	}

	void ObjectHandler::DeleteObject(Object* obj)
	{
		static std::vector<Object*>::iterator it = std::find(this->ObjectsCollection.begin(), this->ObjectsCollection.end(), obj);
		this->ObjectsCollection.erase(it);
	}
}