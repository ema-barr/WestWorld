#include "stdafx.h"

#include "Miner.h"
#include <cassert>

#include "EnterMineAndDigForNuggets.h"
#include "GoHomeAndSleepTilRested.h"
#include <random>


Miner::Miner(int id):
	BaseGameEntity(id),
	m_location(shack),
	m_iGoldCarried(0),
	m_iMoneyInBank(0),
	m_iThirst(0),
	m_iFatigue(0),
	m_loser(false)
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

bool Miner::HandleMessage(const Telegram & message)
{
	return m_pStateMachine->HandleMessage(message);
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

void Miner::SetInsultQuotes(const std::vector<std::string>* quotes)
{
	m_insultQuotes = *quotes;
	m_insultQuotesAvailable = *quotes;
}

void Miner::AddInsulQuote(const std::string & quote)
{
	//Check if the miner already knows the quote
	if (std::find(m_insultQuotes.begin(), m_insultQuotes.end(), quote) == m_insultQuotes.end()) //if it is not found
	{
		m_insultQuotesAvailable.push_back(quote);
		m_insultQuotes.push_back(quote);
	} 
	
}

std::string Miner::GetInsultQuote()
{
	if (m_insultQuotesAvailable.size() > 0)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(0, (int) m_insultQuotesAvailable.size() - 1);

		int numQuote = dist(mt);
		std::string insult = m_insultQuotesAvailable[numQuote];
		m_insultQuotesAvailable.erase(m_insultQuotesAvailable.begin() + numQuote);

		return insult;
	}
	return "";
}

void Miner::RememberInsultQuotes()
{
	m_insultQuotesAvailable = m_insultQuotes;
}

void Miner::SetLoser(bool loser)
{
	m_loser = loser;
}

bool Miner::Loser()
{
	return m_loser;
}

