#include "stdafx.h"
#include "Timer.h"

Timer::Timer(bool immediate_start)
	: start(0), stop(0), counting(false)
{
	// if immediate_start = true, start
	if (immediate_start)
	{
		Start(true);
	}
}

Timer::~Timer()
{
}

/*
* <subject>
* if counting is true
* returns the amount of time
* from timer.start() to timer.stop()
* </subject>
*/
unsigned long Timer::Elapsed() const
{
	return (counting ? std::clock() : stop) - start;
}

void Timer::Start(bool reset)
{
	if (counting) return;
	try {
		if (!counting)
		{
			if (reset)
			{
				start = std::clock();
			}
			counting = true;
		}
	}
	catch (...) {
		printf("Unable to start timer: Unknown Error");
	}
}

/*
* <subject>
* stops the timer counting
* </subject>
*/
void Timer::Stop()
{
	if (counting)
	{
		stop = std::clock();
		counting = false;
	}
}