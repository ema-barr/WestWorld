#include "stdafx.h"
#include "Table.h"
#include <random>
#include "TidyTable.h"

using namespace  std;

Table::Table(int id): 
	BaseGameEntity(id),
	m_location(saloon)
{
	m_pStateMachine = new StateMachine<Table>(this);
	m_pStateMachine->SetCurrentState(TidyTable::Instance());

	//Each table has a probability of 70% to have a bottle on it
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(0.0, 1.0);

	if (dist(mt) <= 0.7)
	{
		SetTableWithBottle(true);
	} else
	{
		SetTableWithBottle(false);
	}
}


Table::~Table()
{
	delete m_pStateMachine;
}

void Table::SetTableWithBottle(bool bottle)
{
	m_tableWithBottle = bottle;
}

bool Table::TableWithBottle() const 
{
	return m_tableWithBottle;
}

StateMachine<Table>* Table::GetFSM() const
{
	return m_pStateMachine;
}

location_type Table::Location() const
{
	return m_location;
}


void Table::Update()
{
	m_pStateMachine->Update();
}

bool Table::HandleMessage(const Telegram & message)
{
	return m_pStateMachine->HandleMessage(message);
}
