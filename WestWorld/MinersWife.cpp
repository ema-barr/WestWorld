#include "stdafx.h"
#include "MinersWife.h"
#include "DoHousework.h"
#include "WifesGlobalState.h"
#include <random>


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

void MinersWife::SetHusbandFought(bool fought)
{
	m_husbandFought = fought;
}

bool MinersWife::HusbandFought() const
{
	return m_husbandFought;
}

void MinersWife::SetInsultQuotes(const std::vector<std::string>* quotes)
{
	m_insultQuotes = *quotes;
	m_insultQuotesAvailable = *quotes;
}

void MinersWife::AddInsulQuote(const std::string & quote)
{
	//Check if the wife already knows the quote
	if (std::find(m_insultQuotes.begin(), m_insultQuotes.end(), quote) == m_insultQuotes.end()) //if it is not found
	{
		m_insultQuotesAvailable.push_back(quote);
		m_insultQuotes.push_back(quote);
	}
}

std::string MinersWife::GetInsultQuote()
{
	if (m_insultQuotesAvailable.size() > 0)
	{
		std::random_device rd;
		std::mt19937 mt(rd());
		std::uniform_int_distribution<int> dist(0, (int)m_insultQuotesAvailable.size() - 1);

		int numQuote = dist(mt);
		std::string insult = m_insultQuotesAvailable[numQuote];
		m_insultQuotesAvailable.erase(m_insultQuotesAvailable.begin() + numQuote);

		return insult;
	}
	return "";
}
