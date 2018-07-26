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

//these telegrams will be stored in a priority queue. Therefore the >
//operator needs to be overloaded so that the PQ can sort the telegrams
//by time priority. Note how the times must be smaller than
//SmallestDelay apart before two Telegrams are considered unique.
const double SmallestDelay = 0.25;


inline bool operator==(const Telegram& t1, const Telegram& t2)
{
	return (fabs(t1.dispatchTime - t2.dispatchTime) < SmallestDelay) &&
		(t1.sender == t2.sender) &&
		(t1.receiver == t2.receiver) &&
		(t1.msg == t2.msg);
}

inline bool operator<(const Telegram& t1, const Telegram& t2)
{
	if (t1 == t2)
	{
		return false;
	}

	else
	{
		return  (t1.dispatchTime < t2.dispatchTime);
	}
}

inline std::ostream& operator<<(std::ostream& os, const Telegram& t) //cosa che stampa se faccio il cout<< variabile
{
	os << "time: " << t.dispatchTime << "  Sender: " << t.sender
		<< "   Receiver: " << t.receiver << "   Msg: " << t.msg;

	return os;
}

//handy helper function for dereferencing the ExtraInfo field of the Telegram 
//to the required type.
template <class T>
inline T DereferenceToType(void* p)
{
	return *(T*)(p);
}


#endif // !TELEGRAM_H
