#include "stdafx.h"
#include "MinersWife.h"
#include "DoHousework.h"
#include "WifesGlobalState.h"


MinersWife::MinersWife(int id) :
	BaseGameEntity(id),
	m_Location(shack)
{
	m_pStateMachine = new StateMachine<MinersWife>(this);

	m_pStateMachine->SetCurrentState(DoHousework::Instance());
	m_pStateMachine->SetGlobalState(WifesGlobalState::Instance());
}

MinersWife::~MinersWife()
{
	delete m_pStateMachine;
}

void MinersWife::Update()
{
	m_pStateMachine->Update();
}

bool MinersWife::HandleMessage(const Telegram & message)
{
	return m_pStateMachine->HandleMessage(message);
}

StateMachine<MinersWife>* MinersWife::GetFSM() const
{
	return m_pStateMachine;
}

location_type MinersWife::Location() const
{
	return m_Location;
}

void MinersWife::ChangeLocation(const location_type loc)
{
	m_Location = loc;
}

void MinersWife::SetCooking(bool cooking)
{
	m_bCooking = cooking;
}

bool MinersWife::Cooking()
{
	return m_bCooking;
}
