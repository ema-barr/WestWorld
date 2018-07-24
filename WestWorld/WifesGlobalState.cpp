#include "stdafx.h"
#include "WifesGlobalState.h"
#include "VisitBathroom.h"
#include <random>
using namespace std;

WifesGlobalState * WifesGlobalState::Instance()
{
	static WifesGlobalState instance;
	return &instance;
}

void WifesGlobalState::Enter(MinersWife * wife)
{
}

void WifesGlobalState::Execute(MinersWife * wife)
{
	//generate a random number between 0 and 1
	random_device rd;
	mt19937 mt(rd());
	uniform_real_distribution<double> dist(0.0, 1.0);

	//1 in 10 chance of needing the bathroom
	if (dist(mt) < 0.1)
	{
		wife->GetFSM()->ChangeState(VisitBathroom::Instance());
	}
}

void WifesGlobalState::Exit(MinersWife * wifer)
{
}
