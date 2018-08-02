#ifndef BARFLY_DRINKING_H
#define BARFLY_DRINKING_H
#include "BarFly.h"

class BarFlyDrinkingState : public State<BarFly>
{
private:
	BarFlyDrinkingState() = default;
public:
	static BarFlyDrinkingState * Instance();

	void Enter(BarFly* barFly) override;
	void Execute(BarFly* barFly) override;
	void Exit(BarFly* barFly) override;
	bool OnMessage(BarFly*, const Telegram&) override;
};

#endif

