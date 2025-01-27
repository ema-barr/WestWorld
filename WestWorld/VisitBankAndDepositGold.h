#ifndef VISIT_BANK_H
#define VISIT_BANK_H

#include "State.h"

class Miner;

class VisitBankAndDepositGold: public State<Miner>
{
private:
	VisitBankAndDepositGold();

public:
	static VisitBankAndDepositGold * Instance();


	// Ereditato tramite State
	virtual void Enter(Miner * pMiner) override;

	virtual void Execute(Miner * pMiner) override;

	virtual void Exit(Miner * pMiner) override;
	bool OnMessage(Miner*, const Telegram&) override;
};

#endif // !VISIT_BANK_H



