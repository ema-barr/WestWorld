#ifndef MINERSWIFE_H
#define MINERSWIFE_H

#include "BaseGameEntity.h"
#include "StateMachine.h"
#include "Locations.h"
#include <vector>

class MinersWife: public BaseGameEntity
{
private:
	//the list of insult quotes known by the miner
	std::vector<std::string> m_insultQuotes;
	std::vector<std::string> m_insultQuotesAvailable;

	//an instance of the state machine class
	StateMachine<MinersWife>*  m_pStateMachine;

	location_type              m_Location;

	bool m_bCooking;

	bool m_husbandFought;
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

	void SetHusbandFought(bool);
	bool HusbandFought() const;


	void SetInsultQuotes(const std::vector<std::string> * quotes);
	void AddInsulQuote(const std::string &quote);
	std::string GetInsultQuote();
};



#endif // !MINERSWIFE_H



