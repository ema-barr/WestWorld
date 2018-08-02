#ifndef BARFLY_INSULTS_H
#define BARFLY_INSULTS_H
#include "State.h"
#include "BarFly.h"

class BarFlyInsults: public State<BarFly>
{
private:
	BarFlyInsults() = default;
public:
	static BarFlyInsults * Instance();


	void Enter(BarFly* barFly) override;
	void Execute(BarFly* barFly) override;
	void Exit(BarFly* barFly) override;
	bool OnMessage(BarFly*, const Telegram&) override;
};

#endif


