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
