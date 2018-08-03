#ifndef  MINERS_MOTHER_INSULTED_H
#define MINERS_MOTHER_INSULTED_H
#include "Miner.h"

class MinersMotherInsulted : public State<Miner>
{
private:
	MinersMotherInsulted() = default;
	static StateMachine<Miner> * mStateMachine;
	bool mWithBottle;
public:
	static MinersMotherInsulted * Instance(StateMachine<Miner> * sm);
	static void SetStateMachine(StateMachine<Miner> * sm);

	void SetWithBottle(bool bottle);
	bool WithBottle() const;

	void Enter(Miner* pMiner) override;
	void Execute(Miner* pMiner) override;
	void Exit(Miner* pMiner) override;
	bool OnMessage(Miner*, const Telegram&) override;
};

#endif
