#include "stdafx.h"
#include "Speedometer.h"

Speedometer::Speedometer(void)
{
	type = "Speedometer";
	status = true;
}

Speedometer::Speedometer(double _speed, std::string _type, bool _status)
{
	type = _type;
	status = _status;
}

Speedometer::~Speedometer(void)
{
}

double Speedometer::getSpeed(void)
{
	return speed;
}

void Speedometer::setSpeed(double _speed)
{
	speed = _speed;
}

void Speedometer::increment(double _amount)
{
	speed += _amount;
}

void Speedometer::decrement(double _amount)
{
	speed -= _amount;
}

