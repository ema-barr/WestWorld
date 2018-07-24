#include "stdafx.h"
#include "GoHomeAndSleepTilRested.h"
#include "EnterMineAndDigForNuggets.h"
#include <iostream>

#include "Miner.h"
#include "EntityNames.h"
#include "Locations.h"
#include "misc/ConsoleUtils.h"
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
