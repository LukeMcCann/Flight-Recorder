#pragma once
#include "stdafx.h"
#include "Sensor.h"

Sensor::Sensor(void)
{
}

Sensor::~Sensor(void)
{
}

double Sensor::getSpeed(void)
{
	return speed;
}

void Sensor::setSpeed(double speed)
{
	this->speed = speed;
}