#include "stdafx.h"
#include "QuenchThirst.h"
#include "Miner.h"
#include "EnterMineAndDigForNuggets.h"
#include "EntityNames.h"
#include <iostream>
using namespace std;

QuenchThirst::QuenchThirst()
{
}

QuenchThirst * QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}

void QuenchThirst::Enter(Miner * pMiner)
{
	if (pMiner->Location() != saloon) {
		pMiner->ChangeLocation(saloon);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "Boy, ah sure is thusty! Walkin' to the saloon";
	}
	
}

void QuenchThirst::Execute(Miner * pMiner)
{
	//if miner feel thirsty
	if (pMiner->Thirsty()) {
		pMiner->BuyAndDrinkAWhiskey();
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "That's mighty fine sippin liquor";

		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNuggets::Instance());
	}
	else {
		cout << "\nERROR\nERROR\nERROR";
	}

}

void QuenchThirst::Exit(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
		<< "Leavin' the saloon, feelin' good";
}

bool QuenchThirst::OnMessage(Miner*, const Telegram&)
{
	return false;
}
