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
		int objectsCount = ObjectHandler::ObjectsCollection.size();
		for (int i = 0; i < objectsCount; i++)
		{
			ObjectHandler::ObjectsCollection[i]->Update();
		}
	}

	void ObjectHandler::AddObject(Object* obj)
	{
		ObjectHandler::ObjectsCollection.push_back(obj);
	}

	void ObjectHandler::DeleteObject(Object* obj)
	{
		std::vector<Object*>::iterator it = std::find(ObjectHandler::ObjectsCollection.begin(), ObjectHandler::ObjectsCollection.end(), obj);
		ObjectHandler::ObjectsCollection.erase(it);
	}
}