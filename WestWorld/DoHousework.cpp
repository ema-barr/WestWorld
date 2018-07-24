#include "stdafx.h"
#include "DoHousework.h"
#include "EntityNames.h"
#include <iostream>

using namespace std;

DoHousework * DoHousework::Instance()
{
	static DoHousework instance;
	return &instance;
}

void DoHousework::Enter(MinersWife * wife)
{
}

void DoHousework::Execute(MinersWife * wife)
{
	//generate random number between 0 and 2
	int random = rand() % 3;
	switch (random)
	{
	case 0:

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": Moppin' the floor";

		break;

	case 1:

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": Washin' the dishes";

		break;

	case 2:

		cout << "\n" << GetNameOfEntity(wife->ID()) << ": Makin' the bed";

		break;
	}
}

void DoHousework::Exit(MinersWife * wife)
{
}
