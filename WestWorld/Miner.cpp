#include "stdafx.h"

#include "Miner.h"
#include <cassert>

#include "EnterMineAndDigForNuggets.h"
#include "GoHomeAndSleepTilRested.h"


Miner::Miner(int id):
	BaseGameEntity(id),
	m_location(shack),
	m_iGoldCarried(0),
	m_iMoneyInBank(0),
	m_iThirst(0),
	m_iFatigue(0)
{
	//set up state machine
	m_pStateMachine = new StateMachine<Miner>(this);
	/*
		NB: si usa new per un controllo più fine, ma poi deve essere distrutto per forza mediante delete. altrimenti avrei dovuto scrivere
		StateMachine<Miner> m_pStateMachine(this);
	*/

	m_pStateMachine->SetCurrentState(GoHomeAndSleepTilRested::Instance());

}

Miner::~Miner() {
	delete m_pStateMachine;
}


void Miner::Update() {
	m_iThirst += 1;

	m_pStateMachine->Update();
}

StateMachine<Miner>* Miner::GetFSM()const {
	return m_pStateMachine;
}

location_type Miner::Location() const
{
	return m_location;
}

void Miner::ChangeLocation(const location_type loc)
{
	m_location = loc;
}

int Miner::GoldCarried() const
{
	return m_iGoldCarried;
}

void Miner::SetGoldCarried(const int val)
{
	m_iGoldCarried = val;
}

void Miner::AddToGoldCarried(const int val)
{
	m_iGoldCarried += val;

	if (m_iGoldCarried < 0) m_iGoldCarried = 0;
}

bool Miner::PocketsFull() const
{
	return m_iGoldCarried >= MaxNuggets;
}

int Miner::Wealth() const
{
	return m_iMoneyInBank;
}

void Miner::SetWealth(const int val)
{
	m_iMoneyInBank = val;
}

void Miner::AddToWealth(const int val) {
	m_iMoneyInBank += val;

	if (m_iMoneyInBank < 0)
		m_iMoneyInBank = 0;
}

bool Miner::Thirsty() const {
	if (m_iThirst >= ThirstLevel) {
		return true;
	}

	return false;
}

void Miner::BuyAndDrinkAWhiskey()
{
	m_iThirst = 0;
	m_iMoneyInBank -= 2;
}

bool Miner::Fatigued() const {
	if (m_iFatigue >= TirednessThreshold) {
		return true;
	}

	return false;
}

void Miner::IncreaseFatigue()
{
	m_iFatigue += 1;
}

void Miner::DecreaseFatigue()
{
	m_iFatigue -= 1;
}

