#ifndef COOK_STEW_H
#define COOK_STEW_H
#include "State.h"
#include "MinersWife.h"

class CookStew : public State<MinersWife>
{
private:
	CookStew() = default;
public:
	static CookStew* Instance();

	void Enter(MinersWife* wife) override;
	void Execute(MinersWife* wife) override;
	void Exit(MinersWife* wife) override;
	bool OnMessage(MinersWife*, const Telegram&) override;
};

#endif
