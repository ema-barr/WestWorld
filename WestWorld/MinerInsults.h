#ifndef  MINER_INSULTS_H
#define MINER_INSULTS_H
#include "Miner.h"

class MinerInsults : public State<Miner>
{
	MinerInsults();
	static StateMachine<Miner> * mStateMachine;
public:
	static MinerInsults * Instance(StateMachine<Miner> * sm);
	static void SetStateMachine(StateMachine<Miner> * sm);

	void Enter(Miner* pMiner) override;
	void Execute(Miner* pMiner) override;
	void Exit(Miner* pMiner) override;
	bool OnMessage(Miner*, const Telegram&) override;
};

#endif

