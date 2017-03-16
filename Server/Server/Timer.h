#include <ctime>
#ifndef TIMER_H
#define TIMER_H

class Timer
{
public:

	explicit Timer(bool immediate_start = false); // start timer immediately
	~Timer();

	void Start(bool reset = false);
	void Stop();

	// returns amount of time elapsed
	unsigned long Elapsed() const;

private:

	bool counting;

	std::clock_t start, stop;

};

#endif
