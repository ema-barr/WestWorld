#include "stdafx.h"
#include "BaseGameEntity.h"
#include <cassert>

int BaseGameEntity::m_iNextValidID = 0;

void BaseGameEntity::SetID(int val)
{
	//make sure the val is equal to or greater than the next available ID
	assert((val >= m_iNextValidID) && "<BaseGameEntity::SetID>: invalid ID");

	m_id = val;

	m_iNextValidID = m_id + 1;
}

BaseGameEntity::BaseGameEntity(int id) {
	SetID(id);
}

BaseGameEntity::~BaseGameEntity() {

}

int BaseGameEntity::ID() const {
	return m_id;
}


