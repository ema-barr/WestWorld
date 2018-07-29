#ifndef ENTER_MINE_AND_DIG_FOR_NUGGETS_H
#define ENTER_MINE_AND_DIG_FOR_NUGGETS_H

#include "State.h"

class Miner;
class EnterMineAndDigForNuggets :public State<Miner>
{
private:
	EnterMineAndDigForNuggets();

	EnterMineAndDigForNuggets(const EnterMineAndDigForNuggets&);
	EnterMineAndDigForNuggets& operator=(const EnterMineAndDigForNuggets&);
public:
	
	//singleton
	static EnterMineAndDigForNuggets* Instance();

	virtual void Enter(Miner * pMiner) override;

	virtual void Execute(Miner * pMiner) override;

	virtual void Exit(Miner * pMiner) override;

	bool OnMessage(Miner*, const Telegram&) override;

};


#endif // !ENTER_MINE_AND_DIG_FOR_NUGGETS_H

