#include "stdafx.h"
#include "BarFlyDrinkingState.h"
#include "MessageTypes.h"
#include "misc/ConsoleUtils.h"
#include "EntityNames.h"
#include "time/CrudeTimer.h"
#include "BarFlyInsults.h"


BarFlyDrinkingState * BarFlyDrinkingState::Instance()
{
	static BarFlyDrinkingState instance;
	return &instance;
}

void BarFlyDrinkingState::Enter(BarFly * barFly)
{

}

void BarFlyDrinkingState::Execute(BarFly * barFly)
{
}

void BarFlyDrinkingState::Exit(BarFly * barFly)
{
	std::cout <<"\n" << GetNameOfEntity(barFly->ID()) <<
		" puts the drink down";
}

bool BarFlyDrinkingState::OnMessage(BarFly * barFly, const Telegram & msg)
{
	switch (msg.msg)
	{
	case Msg_MinerEntersSaloon:
		{
			SetTextColor(BACKGROUND_RED | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			std::cout << "\nMessage handled by " << GetNameOfEntity(barFly->ID())
				<< " at time: " << Clock->GetCurrentTime();

			SetTextColor(FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);

			std::cout << "\n" << GetNameOfEntity(barFly->ID())
				<< ": Oh, "<< GetNameOfEntity(msg.sender) <<"... here you are! " ;

			barFly->GetFSM()->ChangeState(BarFlyInsults::Instance());
		}
		return true;
	}

	return false;
}

