#include "stdafx.h"
#include "TidyTable.h"
#include "MessageTypes.h"
#include "EntityNames.h"
#include "misc/ConsoleUtils.h"
#include "time/CrudeTimer.h"
#include "FlippedTable.h"

using namespace std;

TidyTable * TidyTable::Instance()
{
	static TidyTable instance;
	return &instance;
}

void TidyTable::Enter(Table * pTable)
{
}

void TidyTable::Execute(Table * pTable)
{
}

void TidyTable::Exit(Table * pTable)
{
}

bool TidyTable::OnMessage(Table * table, const Telegram & msg)
{
	switch(msg.msg)
	{
	case Msg_TableFlip:

		SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		cout << "\nMessage handled by " << GetNameOfEntity(table->ID())
			<< " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		cout << "\n" << GetNameOfEntity(msg.sender)
			<< " flipped " << GetNameOfEntity(table->ID());

		table->GetFSM()->ChangeState(FlippedTable::Instance());

		return true;
	}

	return false;
}
