#pragma once
#include "stdafx.h"
#include "Speedometer.h"
#include "RandomGenerator.h"
#include "Sensor.h"
#include "Plane.h"

class DataSim
{
public:
	DataSim();
	~DataSim();

	template <class T>
	T output(int num);

	void speedsim();

private:
	RandomGenerator* r;
};

