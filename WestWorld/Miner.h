#ifndef MINER_H
#define MINER_H

#include "BaseGameEntity.h"
#include "Locations.h"
#include "StateMachine.h"


//the amount of gold a miner must have before he feels comfortable
const int ComfortLevel = 5;
//the amount of nuggets a miner can carry
const int MaxNuggets = 3;
//above this value a miner is thirsty
const int ThirstLevel = 5;
//above this value a miner is sleepy
const int TirednessThreshold = 5;

class Miner : public BaseGameEntity 
{
private:
	//an istance of the state machine class
	StateMachine<Miner>* m_pStateMachine;

	//the place where the miner is currently situated
	location_type m_location;

	//number nuggets in the pockets
	int m_iGoldCarried;

	//number money deposited in the bank
	int m_iMoneyInBank;

	//the higher the value, the thirstier the miner
	int m_iThirst;

	//the higher the value, the more tired the miner
	int m_iFatigue;

	
public:
	Miner(int id);
	~Miner();

	void Update();

	StateMachine<Miner>* GetFSM() const;

	location_type Location()const;
	void ChangeLocation(const location_type loc);

	int GoldCarried()const;
	void SetGoldCarried(const int val);
	void AddToGoldCarried(const int val);
	bool PocketsFull()const;

	int Wealth() const;
	void SetWealth(const int val);
	void AddToWealth(const int val);

	bool Thirsty() const;
	void BuyAndDrinkAWhiskey();

	bool Fatigued() const;
	void IncreaseFatigue();
	void DecreaseFatigue();
	
};

#endif // !MINER_H

