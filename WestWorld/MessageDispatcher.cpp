#include "stdafx.h"
#include "MessageDispatcher.h"
#include "EntityManager.h"
#include "time/CrudeTimer.h"
#include <chrono>
#include <iostream>
#include "EntityNames.h"
#include "MessageTypes.h"

void MessageDispatcher::Discharge(BaseGameEntity * pReceiver, const Telegram & message)
{
	if (!pReceiver->HandleMessage(message))
	{
		std::cout << "Message not handled";
	}
}

MessageDispatcher * MessageDispatcher::Instance()
{
	static MessageDispatcher instance;
	return &instance;
}

void MessageDispatcher::DispatchMessages(double delay, int sender, int receiver, int msg, void * extraInfo)
{
	//get pointers to the sender and receiver
	BaseGameEntity* pSender = EntityMgr->GetEntityFromID(sender);
	BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(receiver);

	//make sure the receiver is valid
	if (pReceiver == nullptr)
	{
		std::cout << "\nWarning! No Receiver with ID of " << receiver << " found";

		return;
	}

	//create the telegram
	Telegram telegram(sender, receiver, msg, SEND_MSG_IMMEDIATELY,  extraInfo);

	//if there is no delay, routhe the telegram
	if (delay <= 0.0)
	{
		std::cout << "\nInstant telegram dispatched at time: " << Clock->GetCurrentTime()
			<< " by " << GetNameOfEntity(pSender->ID()) << " for " << GetNameOfEntity(pReceiver->ID())
			<< ". Msg is " << MsgToStr(msg);



		//send the telegram to the recipient
		Discharge(pReceiver, telegram);
	} else
	{
		double currentTime = Clock->GetCurrentTime();
		
		telegram.dispatchTime = currentTime + delay;

		PriorityQ.insert(telegram);

		std::cout << "\nDelayed telegram from " << GetNameOfEntity(pSender->ID()) << " recorded at time "
			<< Clock->GetCurrentTime() << " for " << GetNameOfEntity(pReceiver->ID())
			<< ". Msg is " << MsgToStr(msg);
	}
}

void MessageDispatcher::DispatchDelayedMessages()
{
	//get current time
	double CurrentTime = Clock->GetCurrentTime();

	//now peek at the queue to see if any telegrams need dispatching.
	//remove all telegrams from the front of the queue that have gone
	//past their sell by date
	while (!PriorityQ.empty() &&
		(PriorityQ.begin()->dispatchTime < CurrentTime) &&
		(PriorityQ.begin()->dispatchTime > 0))
	{
		//read the telegram from the front of the queue
		const Telegram& telegram = *PriorityQ.begin();         //reference variable: telegram e PriorityQ.begin() sono lo stesso oggetto

		//find the recipient
		BaseGameEntity* pReceiver = EntityMgr->GetEntityFromID(telegram.receiver);

		std::cout << "\nQueued telegram ready for dispatch: Sent to "
			<< GetNameOfEntity(pReceiver->ID()) << ". Msg is " << MsgToStr(telegram.msg);

		//send the telegram to the recipient
		Discharge(pReceiver, telegram);

		//remove it from the queue
		PriorityQ.erase(PriorityQ.begin());
	}
}
