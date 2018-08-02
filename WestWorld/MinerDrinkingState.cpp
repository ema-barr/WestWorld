#include "stdafx.h"
#include "MinerDrinkingState.h"
#include "MessageTypes.h"
#include "MinerInsults.h"

StateMachine<Miner> * MinerDrinkingState::mStateMachine = nullptr;

MinerDrinkingState::MinerDrinkingState()
{
}

MinerDrinkingState * MinerDrinkingState::Instance(StateMachine<Miner> * sm)
{
	static MinerDrinkingState instance;
	SetStateMachine(sm);
	return &instance;
}

void MinerDrinkingState::SetStateMachine(StateMachine<Miner> * sm)
{
	mStateMachine = sm;
}

void MinerDrinkingState::Enter(Miner* pMiner)
{
}

void MinerDrinkingState::Execute(Miner* pMiner)
{
}

void MinerDrinkingState::Exit(Miner* pMiner)
{
}

bool MinerDrinkingState::OnMessage(Miner* miner, const Telegram& msg)
{
	switch (msg.msg)
	{
	case Msg_InsultQuote:
	{
		
		mStateMachine->ChangeState(MinerInsults::Instance(mStateMachine));
	}
	return true;
	}
	return false;
}

