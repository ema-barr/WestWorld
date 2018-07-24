#ifndef QUENCH_THIRST_H
#define QUENCH_THIRST_H
#pragma once
#include "State.h"

class Miner;

class QuenchThirst: public State<Miner>
{
private:
	QuenchThirst();
public:
	static QuenchThirst* Instance();


	// Ereditato tramite State
	virtual void Enter(Miner * pMiner) override;

	virtual void Execute(Miner * pMiner) override;

	virtual void Exit(Miner * pMiner) override;

};
#endif // !QUENCH_THIRST_H



