#pragma once
#include "Miner.h"

class MinerDrinkingState : public State<Miner>
{
private:
	MinerDrinkingState();
	static StateMachine<Miner> * mStateMachine;
public:
	static MinerDrinkingState * Instance(StateMachine<Miner> * sm);
	static void SetStateMachine(StateMachine<Miner> * sm);

	void Enter(Miner* pMiner) override;
	void Execute(Miner* pMiner) override;
	void Exit(Miner* pMiner) override;
	bool OnMessage(Miner*, const Telegram&) override;
};

