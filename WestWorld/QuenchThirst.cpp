#include "stdafx.h"
#include "QuenchThirst.h"
#include "Miner.h"
#include "EnterMineAndDigForNuggets.h"
#include "EntityNames.h"
#include <iostream>
#include "MessageDispatcher.h"
#include "MessageTypes.h"
#include "MinerDrinkingState.h"
#include "GoHomeAndSleepTilRested.h"
#include "EntityManager.h"
using namespace std;

QuenchThirst::QuenchThirst()
{
}

QuenchThirst * QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}

StateMachine<Miner>* QuenchThirst::GetFSMInsultFight()
{
	return m_StateMachineInsultFight;
}

void QuenchThirst::Enter(Miner * pMiner)
{
	if (pMiner->Location() != saloon) {
		pMiner->ChangeLocation(saloon);
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "Boy, ah sure is thusty! Walkin' to the saloon";
	}

	m_StateMachineInsultFight = new StateMachine<Miner>(pMiner);
	m_StateMachineInsultFight->SetCurrentState(MinerDrinkingState::Instance(m_StateMachineInsultFight));
	m_StateMachineInsultFight->SetGlobalState(nullptr);

	if (EntityMgr->EntityRegistered(ent_John))
	{
		//alert the bar fly that Bob enters the saloon
		Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
			pMiner->ID(),
			ent_John,
			Msg_MinerEntersSaloon,
			NO_ADDITIONAL_INFO);
	}
	
}

void QuenchThirst::Execute(Miner * pMiner)
{
	m_StateMachineInsultFight->Update();
	if (pMiner->Thirsty() && !pMiner->Loser()) {
		//if miner feel thirsty
		pMiner->BuyAndDrinkAWhiskey();
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "That's mighty fine sippin liquor";

		pMiner->GetFSM()->ChangeState(EnterMineAndDigForNuggets::Instance());
	} else if (pMiner->Thirsty() && pMiner->Loser())
	{
		pMiner->BuyAndDrinkAWhiskey();
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "I have to go";
		pMiner->GetFSM()->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else {
		cout << "\nERROR\nERROR\nERROR";
	}

}

void QuenchThirst::Exit(Miner * pMiner)
{
	if(pMiner->Loser())
	{
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "Leavin' the saloon, but I lost the flyting";
	}else
	{
		cout << "\n" << GetNameOfEntity(pMiner->ID()) << ": "
			<< "Leavin' the saloon, feelin' good";
	}
	

	delete m_StateMachineInsultFight;
}

bool QuenchThirst::OnMessage(Miner* miner, const Telegram& msg)
{
	return m_StateMachineInsultFight->HandleMessage(msg);

}
