#pragma once
#include "Sensor.h"

class Speedometer :
	public Sensor
{
public:
	Speedometer();
	Speedometer(double _speed, std::string _type, bool _status);
	~Speedometer();

	double getSpeed(void);
	void setSpeed(double speed);
	void increment(double amount);
	void decrement(double amount);
};

