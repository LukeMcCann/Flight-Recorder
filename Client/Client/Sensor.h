#pragma once
#include "stdafx.h"
#include "Client.h"
#include <string>

class Sensor
{
public:
	Sensor(void);
	~Sensor(void);

	virtual double getSpeed(void);
	virtual void setSpeed(double speed);

	virtual void increment(double amount) {}
	virtual void decrement(double amount) {}
protected:
	std::string type;
	bool status;
	
	double speed, temp, fuel;

	float altitude, longitude, latitude;
};

