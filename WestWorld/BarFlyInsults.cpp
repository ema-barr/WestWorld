#include "stdafx.h"
#include "BarFlyInsults.h"
#include "MessageTypes.h"
#include "EntityNames.h"
#include "MessageDispatcher.h"
#include "BarFlyDrinkingState.h"
#include "Miner.h"


BarFlyInsults * BarFlyInsults::Instance()
{
	static BarFlyInsults instance;
	
	return &instance;
}

void BarFlyInsults::Enter(BarFly * barFly)
{
	barFly->RememberInsultQuotes();

	Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
		barFly->ID(),
		ent_Miner_Bob,
		Msg_InsultQuote,
		NO_ADDITIONAL_INFO);
}

void BarFlyInsults::Execute(BarFly * barFly)
{

}

void BarFlyInsults::Exit(BarFly * barFly)
{
}

bool BarFlyInsults::OnMessage(BarFly * barFly, const Telegram & msg)
{
	switch (msg.msg)
	{
	case Msg_Fight:
		{
			std::string dereferencedMessage = " ";
			if (msg.extraInfo != NO_ADDITIONAL_INFO)
			{
				dereferencedMessage	= DereferenceToType<std::string>(msg.extraInfo);
			}
			if (dereferencedMessage == "with bottle")
			{
				std::cout << "\n" << GetNameOfEntity(barFly->ID())
					<< ": Please stop. I do not want to die. I am sorry";
			} else
			{
				std::cout << "\n" << GetNameOfEntity(barFly->ID())
					<< ": I am really sorry.";
			}
			Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
				barFly->ID(),
				msg.sender,
				Msg_Sorry,
				NO_ADDITIONAL_INFO);

			barFly->GetFSM()->RevertToPreviousState();
		}
		return true;
	case Msg_InsultQuote:
		{
			std::string dereferencedMsg = " ";

			if (msg.extraInfo != nullptr)
				dereferencedMsg = DereferenceToType<std::string>(msg.extraInfo);
			
			//check if the miner sent him an insult quote
			if (dereferencedMsg == "")
			{
				std::cout << "\n" << GetNameOfEntity(barFly->ID()) <<
					": " << GetNameOfEntity(msg.sender) << " you are a loser... Go away";

				//send a message to miner to inform he is a loser
				Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
					barFly->ID(),
					msg.sender,
					Msg_YouAreALoser,
					NO_ADDITIONAL_INFO);

				barFly->GetFSM()->RevertToPreviousState();
			} else
			{
				std::string quote = barFly->GetInsultQuote();
				if (quote == "")
				{
					std::cout << "\n" << GetNameOfEntity(barFly->ID())
						<< ": ...";

					//Bar fly does not know other insult quotes, so he lose
					Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
						barFly->ID(),
						msg.sender,
						Msg_InsultQuote,
						&quote);

				}
				else
				{
					std::cout << "\n" << GetNameOfEntity(barFly->ID())
						<< ": " << quote;

					//send an insult quote
					Dispatch->DispatchMessages(SEND_MSG_IMMEDIATELY,
						barFly->ID(),
						msg.sender,
						Msg_InsultQuote,
						&quote);
				}
			}


			
		}
		return true;

	case Msg_YouAreALoser:
		{
			std::cout << "\n" << GetNameOfEntity(barFly->ID()) <<
				": " << GetNameOfEntity(msg.sender) << "... You will pay for it";

			
		}
		return true;

	}

	return false;
}
