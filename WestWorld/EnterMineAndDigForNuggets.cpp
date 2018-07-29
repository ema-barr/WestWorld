#include "stdafx.h"
#include "EnterMineAndDigForNuggets.h"
#include "VisitBankAndDepositGold.h"
#include "QuenchThirst.h"

#include <iostream>
#include "Miner.h"
#include "EntityNames.h"

using namespace std;

EnterMineAndDigForNuggets::EnterMineAndDigForNuggets()
{
}


EnterMineAndDigForNuggets * EnterMineAndDigForNuggets::Instance()
{
	static EnterMineAndDigForNuggets instance; //questa è una chiamata al costruttore
	return &instance;
}

void EnterMineAndDigForNuggets::Enter(Miner * pMiner)
{
	//if the miner is not already located at the gold mine, he must change location
	if (pMiner->Location() != goldmine) {
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "Walkin' to the gold mine";

		pMiner->ChangeLocation(goldmine);
	}

}

void EnterMineAndDigForNuggets::Execute(Miner * pMiner)
{
	//the miner digs for gold until he is carrying in excess of MaxNuggets
	//if he gets thirty during his digging he stops work and changes state to go to the saloon for a whiskey
	pMiner->AddToGoldCarried(1);

	//digging' is hard work
	pMiner->IncreaseFatigue();

	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
		<< "Pickin' up a nugget";

	//if enough gold mined, go and put it in the bank
	if (pMiner->PocketsFull()) {
		pMiner->GetFSM()->ChangeState(VisitBankAndDepositGold::Instance());
	}

	//if thirsty go and get a whiskey
	if (pMiner->Thirsty()) {
		pMiner->GetFSM()->ChangeState(QuenchThirst::Instance());
	}
}

void EnterMineAndDigForNuggets::Exit(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
		<< "Ah'm leavin' the gold mine with mah pockets full o' sweet gold";
}

bool EnterMineAndDigForNuggets::OnMessage(Miner *, const Telegram &)
{
	return false;
}
