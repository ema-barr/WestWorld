#ifndef DOHOUSEWORK_H
#define DOHOUSEWORK_H

#include "State.h"
#include "MinersWife.h"

class DoHousework: public State<MinersWife>
{
private:
	DoHousework() {}
public:
	static DoHousework * Instance();
	
	// Ereditato tramite State
	virtual void Enter(MinersWife * wife) override;
	virtual void Execute(MinersWife * wife) override;
	virtual void Exit(MinersWife * wife) override;
};
#endif // !DOHOUSEWORK_H


