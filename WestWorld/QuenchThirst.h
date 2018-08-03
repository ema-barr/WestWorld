#ifndef QUENCH_THIRST_H
#define QUENCH_THIRST_H
#include "State.h"
#include "StateMachine.h"

class Miner;

class QuenchThirst: public State<Miner>
{
private:
	StateMachine<Miner> * m_StateMachineInsultFight;
	QuenchThirst();

public:
	static QuenchThirst* Instance();

	StateMachine<Miner> * GetFSMInsultFight();

	// Ereditato tramite State
	virtual void Enter(Miner * pMiner) override;

	virtual void Execute(Miner * pMiner) override;

	virtual void Exit(Miner * pMiner) override;
	bool OnMessage(Miner*, const Telegram&) override;

};
#endif // !QUENCH_THIRST_H



