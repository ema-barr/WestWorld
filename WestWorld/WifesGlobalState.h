#ifndef WIFESGLOBALSTATE_H
#define WIFESGLOBALSTATE_H

#pragma once
#include "State.h"
#include "MinersWife.h"

class WifesGlobalState : public State <MinersWife>
{
private:
	WifesGlobalState(){}
public:
	static WifesGlobalState * Instance();


	// Ereditato tramite State
	virtual void Enter(MinersWife * wife) override;

	virtual void Execute(MinersWife * wife) override;

	virtual void Exit(MinersWife * wifer) override;

};

#endif

