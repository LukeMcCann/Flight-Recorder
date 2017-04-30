#pragma once
#include "Sensor.h"
class Speedometer :
	public Sensor
{
public:
	Speedometer(void);
	~Speedometer(void);

	double readSensor(double _speed);
};

