#ifndef CRUDETIMER_H
#define CRUDETIMER_H

//------------------------------------------------------------------------
//
//  Name:   CrudeTimer.h
//
//  Desc:   timer to measure time in seconds
//
//  Author: Mat Buckland 2002 (fup@ai-junkie.com)
//
//------------------------------------------------------------------------


#include <chrono>


#define Clock CrudeTimer::Instance()

class CrudeTimer
{
private:


	//set to the time (in seconds) when class is instantiated
	double m_dStartTime;

	//set the start time
	CrudeTimer()
	{
		auto current_time = std::chrono::system_clock::now();
		auto duration_in_seconds = std::chrono::duration<double>(current_time.time_since_epoch());

		m_dStartTime = duration_in_seconds.count();
		
	}

	//copy ctor and assignment should be private
	CrudeTimer(const CrudeTimer&);
	CrudeTimer& operator=(const CrudeTimer&);

public:

	static CrudeTimer* Instance();

	//returns how much time has elapsed since the timer was started
	double GetCurrentTime()
	{
		auto current_time = std::chrono::system_clock::now();
		auto duration_in_seconds = std::chrono::duration<double>(current_time.time_since_epoch());  //senza nulla vicino al double vuol dire che prendo i secondi.

		return duration_in_seconds.count() - m_dStartTime;
	}

};







#endif