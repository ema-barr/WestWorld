#include "stdafx.h"
#include "GoHomeAndSleepTilRested.h"
#include "EnterMineAndDigForNuggets.h"
#include <iostream>

#include "Miner.h"
#include "EntityNames.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "time/CrudeTimer.h"
#include "EatStew.h"
using namespace std;

GoHomeAndSleepTilRested::GoHomeAndSleepTilRested()
{
}

GoHomeAndSleepTilRested * GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner * pMiner)
{
	if (pMiner->Location() != shack) {
		pMiner->ChangeLocation(shack);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "Walkin' home";

		Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
			pMiner->ID(),
			ent_Elsa,
			Msg_HiHoneyImHome,
			NO_ADDITIONAL_INFO);
	}

}
	

void GoHomeAndSleepTilRested::Execute(Miner * pMiner)
{
	if (!pMiner->Fatigued()) {
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "What a God darn fantastic nap! Time to find more gold";

		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNuggets::Instance());
	}
	else {
		pMiner->DecreaseFatigue();
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "ZZZZ... ";
	}
}

void GoHomeAndSleepTilRested::Exit(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
		<< "Leaving the house";
}

bool GoHomeAndSleepTilRested::OnMessage(Miner * pMiner, const Telegram & msg)
{

	switch (msg.msg)
	{
	case Msg_StewReady:
		{
			SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			cout << "\nMessage handled by " << GetNameOfEntity(pMiner->ID())
				<< " at time: " << Clock->GetCurrentTime();

			SetTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			cout << "\n" << GetNameOfEntity(pMiner->ID())
				<< ": Okay hun, ahm a-comin!";

			pMiner->GetFSM()->ChangeState(EatStew::Instance());

		}
		return true;
	}
	return false;
}
