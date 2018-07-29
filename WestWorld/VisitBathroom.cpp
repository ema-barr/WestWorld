#include "stdafx.h"
#include "VisitBathroom.h"
#include "EntityNames.h"
#include <iostream>

using namespace std;

VisitBathroom * VisitBathroom::Instance()
{
	static VisitBathroom instance;
	return &instance;
}

void VisitBathroom::Enter(MinersWife* wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Walkin' to the can. Need to powda mah pretty li'lle nose";
}


void VisitBathroom::Execute(MinersWife* wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Ahhhhhh! Sweet relief!";

	wife->GetFSM()->RevertToPreviousState();
}

void VisitBathroom::Exit(MinersWife* wife)
{
	cout << "\n" << GetNameOfEntity(wife->ID()) << ": Leavin' the Jon";
}

bool VisitBathroom::OnMessage(MinersWife*, const Telegram&)
{
	return false;
}
