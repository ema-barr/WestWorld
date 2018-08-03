#ifndef MINER_H
#define MINER_H

#include "BaseGameEntity.h"
#include "Locations.h"
#include "StateMachine.h"
#include <vector>
#include <string>



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


	//the list of insult quotes known by the miner
	std::vector<std::string> m_insultQuotes;
	//the list of insult quotes available. The miner can't use the same quote twice a day
	std::vector<std::string> m_insultQuotesAvailable; 

	//an istance of the state machine class
	StateMachine<Miner>* m_pStateMachine;

	//the place where the miner is currently situated
	location_type m_location;

	bool m_signOfStruggle;

	bool m_loser;

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

	void Update() override;
	bool HandleMessage(const Telegram& message) override;

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

	void SetSignsStruggle(bool);
	bool SignsStruggle() const;

	bool Thirsty() const;
	void BuyAndDrinkAWhiskey();

	bool Fatigued() const;
	void IncreaseFatigue();
	void DecreaseFatigue();

	void SetInsultQuotes(const std::vector<std::string> * quotes);
	void AddInsultQuote(const std::string &quote);
	std::string GetInsultQuote();
	void RememberInsultQuotes();

	void SetLoser(bool loser);
	bool Loser();
};

#endif // !MINER_H

