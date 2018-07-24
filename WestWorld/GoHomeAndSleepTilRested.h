#ifndef GO_HOME_AND_SLEEP_H
#define GO_HOME_AND_SLEEP_H

#pragma once
#include "State.h"

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

};


#endif // !GO_HOME_AND_SLEEP_H


