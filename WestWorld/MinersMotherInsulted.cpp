#include "stdafx.h"
#include "MinersMotherInsulted.h"
#include "EntityNames.h"
#include "MessageTypes.h"
#include "MinerDrinkingState.h"
#include "MessageDispatcher.h"

using namespace std;

StateMachine<Miner> * MinersMotherInsulted::mStateMachine = nullptr;

MinersMotherInsulted * MinersMotherInsulted::Instance(StateMachine<Miner>* sm)
{
	static MinersMotherInsulted instance;
	SetStateMachine(sm);
	return &instance;
}

void MinersMotherInsulted::SetStateMachine(StateMachine<Miner>* sm)
{
	mStateMachine = sm;
}

void MinersMotherInsulted::SetWithBottle(bool bottle)
{
	mWithBottle = bottle;

	if (bottle)
	{
		cout << "\n" << "A bottle has been found";
	}
}

bool MinersMotherInsulted::WithBottle() const
{
	return mWithBottle;
}

void MinersMotherInsulted::Enter(Miner * pMiner)
{
	SetWithBottle(false);

	cout << "\n" << GetNameOfEntity(pMiner->ID())
		<< ": NON TI PERMETTERE";

	cout << "\n" << GetNameOfEntity(pMiner->ID())
		<< ": ASSOLUTAMENTE";

	cout << "\n" << GetNameOfEntity(pMiner->ID())
		<< ": DI NOMINARE MIA MADRE";

	cout << "\n" << GetNameOfEntity(pMiner->ID())
		<< ": MAI PIU' !!!";

	Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
		pMiner->ID(),
		table_1,
		Msg_IsThereABottle,
		NO_ADDITIONAL_INFO);

	if (!WithBottle())
	{
		Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
			pMiner->ID(),
			table_2,
			Msg_IsThereABottle,
			NO_ADDITIONAL_INFO);
	}
	
	if (!WithBottle())
	{
		Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
			pMiner->ID(),
			table_3,
			Msg_IsThereABottle,
			NO_ADDITIONAL_INFO);
	}

	if (WithBottle())
	{
		//the miner breaks the bottle and he starts threatening its opponenet
		std::cout << "\n" << GetNameOfEntity(pMiner->ID())
			<< " breaks the bottle and he starts threatening the bar fly";

		string string = "with bottle";
		Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
			pMiner->ID(),
			ent_John,
			Msg_Fight,
			&string);

		Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
			pMiner->ID(),
			ent_Elsa,
			Msg_ThereWasAFight,
			NO_ADDITIONAL_INFO);
		

	} else
	{
		//the miner has not a bottle, so he will flip the first table and he will start a fight
		Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
			pMiner->ID(),
			table_1,
			Msg_TableFlip,
			NO_ADDITIONAL_INFO);

		cout << "\nA fight breaks out";

		Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
			pMiner->ID(),
			ent_John,
			Msg_Fight,
			NO_ADDITIONAL_INFO);

		pMiner->SetSignsStruggle(true);
	}
	

}

void MinersMotherInsulted::Execute(Miner * pMiner)
{
}

void MinersMotherInsulted::Exit(Miner * pMiner)
{
}

bool MinersMotherInsulted::OnMessage(Miner * pMiner, const Telegram & msg)
{
	switch(msg.msg)
	{
	case Msg_TableAnswer:
		{
			bool dereferencedMessage = DereferenceToType<bool>(msg.extraInfo);
			SetWithBottle(dereferencedMessage);
		}
		return true;
	case Msg_Sorry:
		{
			cout << "\n" << GetNameOfEntity(pMiner->ID())
				<< ": Chill, yes! Chill now.";
			mStateMachine->ChangeState(MinerDrinkingState::Instance(mStateMachine));
		}
		return true;
	}
	return false;
}

