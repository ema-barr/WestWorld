#include "stdafx.h"
#include "MinerInsults.h"
#include "EntityNames.h"
#include "MessageTypes.h"
#include "MessageDispatcher.h"
#include "GoHomeAndSleepTilRested.h"
#include "MinerDrinkingState.h"

StateMachine<Miner> * MinerInsults::mStateMachine = nullptr;

MinerInsults::MinerInsults()
{
}

MinerInsults * MinerInsults::Instance(StateMachine<Miner> * sm)
{
	static MinerInsults instance;
	SetStateMachine(sm);
	return &instance;
}

void MinerInsults::SetStateMachine(StateMachine<Miner>* sm)
{
	mStateMachine = sm;
}

void MinerInsults::Enter(Miner * pMiner)
{
	pMiner->RememberInsultQuotes();
	std::cout << "\n" << GetNameOfEntity(pMiner->ID())
		<< ": I do not want to fight with you.";

	Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
		pMiner->ID(),
		ent_John,
		Msg_InsultQuote,
		NO_ADDITIONAL_INFO);
}

void MinerInsults::Execute(Miner * pMiner)
{
}

void MinerInsults::Exit(Miner * pMiner)
{
}

bool MinerInsults::OnMessage(Miner * miner, const Telegram & msg)
{
	switch (msg.msg)
	{
	case Msg_InsultQuote:
	{
		std::string dereferencedMsg = " ";

		if (msg.extraInfo != nullptr)
			dereferencedMsg = DereferenceToType<std::string>(msg.extraInfo);

		//check if the bar fly sent him an insult quote
		if (dereferencedMsg == "")
		{
			std::cout << "\n" << GetNameOfEntity(miner->ID()) <<
				": " << GetNameOfEntity(msg.sender) << " you are a loser... Go away";

			//send a message to bar fly to inform he is a loser
			Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
				miner->ID(),
				ent_John,
				Msg_YouAreALoser,
				NO_ADDITIONAL_INFO);

			mStateMachine->ChangeState(MinerDrinkingState::Instance(mStateMachine));
		}
		else
		{
			std::string quote = miner->GetInsultQuote();
			if (quote == "")
			{

				std::cout << "\n" << GetNameOfEntity(miner->ID())
					<< ": ...";

				//Miner does not know other insult quotes, so he lose
				Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
					miner->ID(),
					ent_John,
					Msg_InsultQuote,
					&quote);


			}
			else
			{
				std::cout << "\n" << GetNameOfEntity(miner->ID())
					<< ": " << quote;

				//send an insult quote
				Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
					miner->ID(),
					ent_John,
					Msg_InsultQuote,
					&quote);
			}
		}



	}
	return true;

	case Msg_YouAreALoser:
	{
		std::cout << "\n" << GetNameOfEntity(miner->ID()) <<
			": " << GetNameOfEntity(msg.sender) << "... You will pay for it";

		//if the miner loose, he goes to home
		miner->SetLoser(true);
	}
	return true;

	}



	return false;
}
