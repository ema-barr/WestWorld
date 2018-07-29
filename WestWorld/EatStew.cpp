#include "stdafx.h"
#include "EatStew.h"
#include "EntityNames.h"

using namespace  std;

EatStew * EatStew::Instance()
{
	static EatStew instance;
	return &instance;
}

void EatStew::Enter(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Smells Reaaal goood Elsa!";
}

void EatStew::Execute(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": " << "Tastes real good too!";

	pMiner->GetFSM()->RevertToPreviousState();
}

void EatStew::Exit(Miner * pMiner)
{
	cout << "\n" << GetNameOfEntity(pMiner->ID())
		<< ": Thank ya li'l lady. Ah better get back to whatever ah wuz doin'";

}

bool EatStew::OnMessage(Miner *, const Telegram &)
{
	return false;
}
