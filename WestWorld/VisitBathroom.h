#ifndef VISITBATHROOM_H
#define VISITBATHROOM_H

#include "State.h"
#include "MinersWife.h"
class VisitBathroom : public State <MinersWife>
{
private:
	VisitBathroom() {}
public:
	static VisitBathroom * Instance();

	// Ereditato tramite State
	virtual void Enter(MinersWife * wife) override;
	virtual void Execute(MinersWife * wife) override;
	virtual void Exit(MinersWife * wife) override;
};

#endif // !VISITBATHROOM_H


