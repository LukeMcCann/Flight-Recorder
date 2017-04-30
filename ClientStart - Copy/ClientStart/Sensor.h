#pragma once
#include "stdafx.h"
class Sensor
{
public:
	Sensor(void);
	~Sensor(void);

	virtual double readSensor(double _data);
};

