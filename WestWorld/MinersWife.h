#ifndef MINERSWIFE_H
#define MINERSWIFE_H

#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Locations.h"

class MinersWife: public BaseGameEntity
{
private:
	//an instance of the state machine class
	StateMachine<MinersWife>*  m_pStateMachine;

	location_type              m_Location;

	bool m_bCooking;
public:
	MinersWife(int id);
	~MinersWife();

	void Update() override;
	bool HandleMessage(const Telegram& message) override;

	StateMachine<MinersWife>* GetFSM()const;

	location_type Location()const;
	void ChangeLocation(const location_type loc);

	void SetCooking(bool);
	bool Cooking();
};



#endif // !MINERSWIFE_H



