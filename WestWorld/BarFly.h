#ifndef BARFLY_H
#define BARFLY_H
#include "BaseGameEntity.h"
#include "Locations.h"
#include <vector>
#include "StateMachine.h"

class BarFly: public BaseGameEntity
{
private:
	//the list of insult quotes known by the miner
	std::vector<std::string> m_insultQuotes;
	std::vector<std::string> m_insultQuotesAvailable;

	//an instance of the state machine class
	StateMachine<BarFly>*  m_pStateMachine;

	location_type              m_Location;

	bool m_bCooking;
public:
	BarFly(int id);
	~BarFly();

	void Update() override;
	bool HandleMessage(const Telegram& message) override;

	StateMachine<BarFly> * GetFSM() const;
	location_type Location()const;
	void ChangeLocation(const location_type loc);

	void SetInsultQuotes(const std::vector<std::string> * quotes);
	void AddInsulQuote(const std::string &quote);
	std::string GetInsultQuote();
	void RememberInsultQuotes();
};

#endif