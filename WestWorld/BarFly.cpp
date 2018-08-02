#include "stdafx.h"
#include "BarFly.h"
#include <random>
#include "BarFlyDrinkingState.h"


BarFly::BarFly(int id):
	BaseGameEntity(id),
	m_Location(saloon)
{
	m_pStateMachine = new StateMachine<BarFly>(this);
	m_pStateMachine->SetCurrentState(BarFlyDrinkingState::Instance());
	m_pStateMachine->SetGlobalState(nullptr);

}

BarFly::~BarFly()
{
	delete m_pStateMachine;
}

void BarFly::Update()
{
	m_pStateMachine->Update();
}

bool BarFly::HandleMessage(const Telegram & message)
{
	return m_pStateMachine->HandleMessage(message);;
}

StateMachine<BarFly>* BarFly::GetFSM() const
{
	return m_pStateMachine;
}

location_type BarFly::Location() const
{
	return m_Location;
}

void BarFly::ChangeLocation(const location_type loc)
{
	m_Location = loc;
}

void BarFly::SetInsultQuotes(const std::vector<std::string>* quotes)
{
	m_insultQuotes = *quotes;
	m_insultQuotesAvailable = *quotes;
}

void BarFly::AddInsulQuote(const std::string & quote)
{
	//Check if the bar fly already knows the quote
	if (std::find(m_insultQuotes.begin(), m_insultQuotes.end(), quote) == m_insultQuotes.end()) //if it is not found
	{
		m_insultQuotesAvailable.push_back(quote);
		m_insultQuotes.push_back(quote);
	}
}

std::string BarFly::GetInsultQuote()
{
	if (m_insultQuotesAvailable.size()>0)
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

void BarFly::RememberInsultQuotes()
{
	m_insultQuotesAvailable = m_insultQuotes;
}
