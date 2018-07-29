#include "stdafx.h"
#include "WifesGlobalState.h"
#include "VisitBathroom.h"
#include <random>
#include "MessageTypes.h"
#include "EntityNames.h"
#include "time/CrudeTimer.h"
#include "misc/ConsoleUtils.h"
#include "CookStew.h"



using namespace std;

WifesGlobalState * WifesGlobalState::Instance()
{
	static WifesGlobalState instance;
	return &instance;
}

void WifesGlobalState::Enter(MinersWife * wife)
{
}

void WifesGlobalState::Execute(MinersWife * wife)
{
	//generate a random number between 0 and 1
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(0.0, 1.0);

	//1 in 10 chance of needing the bathroom
	if (dist(mt) < 0.1)
	{
		wife->GetFSM()->ChangeState(VisitBathroom::Instance());
	}
}

void WifesGlobalState::Exit(MinersWife * wifer)
{
}

bool WifesGlobalState::OnMessage(MinersWife * wife, const Telegram & msg)
{

	switch(msg.msg)
	{
	case Msg_HiHoneyImHome:
		{
		SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		cout << "\nMessage handled by " << GetNameOfEntity(wife->ID())
			<< " at time: " << Clock->GetCurrentTime();

		SetTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

		cout << "\n" << GetNameOfEntity(wife->ID()) <<
			": Hi honey. Let me make some of mah fine country stew";

		wife->GetFSM()->ChangeState(CookStew::Instance());
		}
		return true;
	}

	return false;
}
