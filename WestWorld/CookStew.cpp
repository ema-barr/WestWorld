#include "stdafx.h"
#include "CookStew.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "time/CrudeTimer.h"
#include "DoHousework.h"

using namespace std;

CookStew* CookStew::Instance()
{
	static CookStew instance;
	return &instance;
}

void CookStew::Enter(MinersWife * wife)
{

	//if not already cooking, put the stew in the oven
	if (!wife->Cooking())
	{
		cout << "\n" << GetNameOfEntity(wife->ID())
			<< ": Puttin' the stew in the oven";

		//send a delayed message to myself so that I know when to take the stew out the oven

		Dispatch->DispatchMessages(1.5,
			wife->ID(),
			wife->ID(),
			Msg_StewReady,
			NO_ADDITIONAL_INFO);

		wife->SetCooking(true);
	}
}

void CookStew::Execute(MinersWife * wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Fussin' over food";
}

void CookStew::Exit(MinersWife * wife)
{

	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Puttin' the stew on the table";
}

bool CookStew::OnMessage(MinersWife * wife, const Telegram & msg)
{
	
	switch(msg.msg)
	{
	case Msg_StewReady:
		{
			SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			cout << "\nMessage received by " << GetNameOfEntity(wife->ID())
				<< " at time: " << Clock->GetCurrentTime();

			SetTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			cout << "\n" << GetNameOfEntity(wife->ID())
				<< ": Stew ready. Let's eat";

			//let hubby kwno the stew is ready
			Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
				wife->ID(),
				ent_Miner_Bob,
				Msg_StewReady,
				NO_ADDITIONAL_INFO);

			wife->SetCooking(false);

			wife->GetFSM()->ChangeState(DoHousework::Instance());
		}
		return true;
	}

	return false;
}
