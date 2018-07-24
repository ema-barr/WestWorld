#ifndef MINERSWIFE_H
#define MINERSWIFE_H
#pragma once

#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Locations.h"

class MinersWife: public BaseGameEntity
{
private:
	//an instance of the state machine class
	StateMachine<MinersWife>*  m_pStateMachine;

	location_type              m_Location;
public:
	MinersWife(int id);
	~MinersWife();

	void Update();

	StateMachine<MinersWife>* GetFSM()const;

	location_type Location()const;
	void ChangeLocation(const location_type loc);
};



#endif // !MINERSWIFE_H


