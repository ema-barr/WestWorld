#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H
#include "BaseGameEntity.h"
#include <map>

class EntityManager
{
private:

	//to save the ol' fingers
	typedef std::map<int, BaseGameEntity*> EntityMap;

	//to facilitate quick lookup the enitites are stored in a map
	EntityMap m_EntityMap;

	EntityManager() = default;

	EntityManager(const EntityManager&);
	EntityMap& operator = (const EntityManager&);

public:

	static EntityManager* Instance();

	//this method stores a pointer to the entity in the vector m_Entities at the index position indicated by the entity's ID
	void RegisterEntity(BaseGameEntity* newEntity);

	//returns a pointer to the the entity with the ID given as parameter
	BaseGameEntity* GetEntityFromID(int id) const;

	//this method removs the entity from the list
	void RemoveEntity(BaseGameEntity* pEntity);

	bool EntityRegistered(int id);

};

//provide easy access to the instance of the EntityManager
#define EntityMgr EntityManager::Instance()

#endif

