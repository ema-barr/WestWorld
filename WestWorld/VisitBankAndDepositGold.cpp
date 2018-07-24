#include "stdafx.h"
#include "VisitBankAndDepositGold.h"
#include "GoHomeAndSleepTilRested.h"
#include "EnterMineAndDigForNuggets.h"
#include "Miner.h"
#include "EntityNames.h"
#include <iostream>

using namespace std;

VisitBankAndDepositGold::VisitBankAndDepositGold()
{
}

VisitBankAndDepositGold * VisitBankAndDepositGold::Instance()
{
	static VisitBankAndDepositGold instance;
	return &instance;
}

void VisitBankAndDepositGold::Enter(Miner * pMiner)
{
	
	if (pMiner->Location() != bank) {
		//the miner go to the bank
		pMiner->ChangeLocation(bank);

		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "Goin' to the bank. Yes siree";

	}
	
}

void VisitBankAndDepositGold::Execute(Miner * pMiner)
{
	//deposit nuggets
	pMiner->AddToWealth(pMiner->GoldCarried());
	pMiner->SetGoldCarried(0);

	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
		<< "Depositing gold. Total savings now: " << pMiner->Wealth();

	//if he consider himself wealthy enough, go to home
	if (pMiner->Wealth() >= ComfortLevel) {
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "WooHoo! Rich enough for now. Back home to mah li'lle lady";
		pMiner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else {
		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNuggets::Instance());
	}
}

void VisitBankAndDepositGold::Exit(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
		<< "Leavin' the bank";
}
