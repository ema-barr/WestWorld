#ifndef GO_HOME_AND_SLEEP_H
#define GO_HOME_AND_SLEEP_H

#include "State.h"
#include "EntityNames.h"
#include "MessageTypes.h"

class Miner;

class GoHomeAndSleepTilRested: public State<Miner>
{
private:
	GoHomeAndSleepTilRested();

public:

	static  GoHomeAndSleepTilRested* Instance();

	// Ereditato tramite State
	virtual void Enter(Miner* pMiner) override;

	virtual void Execute(Miner* pMiner) override;

	virtual void Exit(Miner* pMiner) override;

	bool OnMessage(Miner*, const Telegram&) override;

};


#endif // !GO_HOME_AND_SLEEP_H


