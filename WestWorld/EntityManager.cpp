#include "stdafx.h"
#include "EntityManager.h"
#include <cassert>

EntityManager * EntityManager::Instance()
{
	static EntityManager instance;
	return &instance;
}

void EntityManager::RegisterEntity(BaseGameEntity * newEntity)
{
	m_EntityMap.insert(std::make_pair(newEntity->ID(), newEntity));
}

BaseGameEntity * EntityManager::GetEntityFromID(int id) const
{
	//find the entity
	EntityMap::const_iterator ent = m_EntityMap.find(id);

	//assert that the entity is a member of the map
	assert((ent != m_EntityMap.end()) && "<EntityManager::GetEntityFromID>: invalid ID");

	return ent->second;  //first è la chiave, second è il valore
}

void EntityManager::RemoveEntity(BaseGameEntity * pEntity)
{
	m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
}
