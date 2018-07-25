#ifndef TELEGRAM_H
#define TELEGRAM_H

struct Telegram
{
	//the entity that sent this telegram
	int sender;

	//the entity that is to receive this telegram
	int receiver;

	//the message itself. These are all enumarated in the file "MessageTypes.h"
	int msg;

	//messages can be dispatched immediately or delaed for a specific amount of time. If a delay is necessary, this field is stamped with the time the message should be dispatched
	double dispatchTime;

	//any additional information that may accompany the message
	void* extraInfo;

	Telegram() :
		sender(-1),
		receiver(-1),
		msg(-1),
		dispatchTime(-1),
		extraInfo(nullptr)
	{}

	Telegram(int sender, int receiver, int msg, double time, void* info) :
		sender(sender),
		receiver(receiver),
		msg(msg),
		dispatchTime(time),
		extraInfo(info)
	{}
};

#endif // !TELEGRAM_H
