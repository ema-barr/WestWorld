#ifndef MESSAGE_DISPATCHER_H
#define MESSAGE_DISPATCHER_H
#include <set>
#include "messaging/Telegram.h"

//to make code easier to read
const double SEND_MSG_IMMEDIATELY = 0.0f;
const int   NO_ADDITIONAL_INFO = 0;

class BaseGameEntity;

class MessageDispatcher
{
private:
	//a std::set is used as the container for the delayed messages because of the benefit of automatic sorting and avoidance of duplcates. Messages are sorted by their dispatch time
	std::set<Telegram> PriorityQ;

	//this method is utilized by DispatchMessages or DispatchDelayedMessages. 
	//This method calls the message handling member function of the receiving entity, pReceiver, with the newly created telegram
	void Discharge(BaseGameEntity* pReceiver, const Telegram& message);

	MessageDispatcher() = default;

public:

	//this class is singleton
	static MessageDispatcher* Instance();

	//send a message to another agent
	void DispatchMessages(double delay, int sender, int receiver, int msg, void* extraInfo);

	//send out any delayed messages. This method is called each time through the main game loop
	void DispatchDelayedMessages();
};

#define Dispatch MessageDispatcher::Instance();

#endif
