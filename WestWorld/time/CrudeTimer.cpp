#include "stdafx.h"
#include "CrudeTimer.h"

CrudeTimer * CrudeTimer::Instance()
{
	static CrudeTimer instance;
	return &instance;
}
