#ifndef ENTITY_H
#define ENTITY_H



#pragma once
class BaseGameEntity
{
private:
	//every entity has a unique identifying number
	int m_id;

	//this is the next valid ID
	static int m_iNextValidID;

	//this is called within the constructor to create ID
	void SetID(int val);

public:
	BaseGameEntity(int id);

	virtual ~BaseGameEntity();

	virtual void Update() = 0;

	int ID() const;
};
#endif // !ENTITY_H
