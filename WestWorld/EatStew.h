#ifndef EAT_STEW_H
#define EAT_STEW_H
#include "State.h"
#include "Miner.h"

class EatStew :	public State<Miner>
{
private:
	EatStew() = default;
public:
	static EatStew * Instance();

	void Enter(Miner* pMiner) override;
	void Execute(Miner* pMiner) override;
	void Exit(Miner* pMiner) override;
	bool OnMessage(Miner*, const Telegram&) override;
};


#endif
