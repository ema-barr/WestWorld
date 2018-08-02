#include "stdafx.h"
#include "FlippedTable.h"

FlippedTable * FlippedTable::Instance()
{
	static FlippedTable instance;
	return &instance;
}

void FlippedTable::Enter(Table * pMiner)
{
}

void FlippedTable::Execute(Table * pMiner)
{
}

void FlippedTable::Exit(Table * pMiner)
{
}

bool FlippedTable::OnMessage(Table *, const Telegram &)
{
	return false;
}
