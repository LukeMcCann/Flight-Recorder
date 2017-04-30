/*
* SpeedSim class
* simulates realistic speed data for aircraft
* this class acts as the plane generating data
*
* Methods:
*    start() - starts the simulation
*    simulateSpeed - simulates advanced speed
*    basicSpeedSim - simulates basic speed
*
*   TODO: Integrate WindGenerator class
*
* @Author - Luke McCann
* @Date - 08/04/2017
* @Version - 15.3
*/
#pragma once
#include "stdafx.h"
#include "RandomGenerator.h"
#include "Speedometer.h"

class SpeedSim
{
public:
	SpeedSim(void);
	SpeedSim(double _minS, double _maxS);
	~SpeedSim(void);

	// main method
	void start();

	// getters and setters
	double getSpeed(void);
	void setSpeed(double _speed);

	// min/max - getters and setters
	double getMinSpeed(void);
	void setMinSpeed(double _speed);
	double getMaxSpeed();
	void setMaxSpeed(double _speed);

private:

	RandomGenerator * random;

	bool firstRun = true;

	double speed,
		MAX_SAFE_SPEED, MIN_SAFE_SPEED;

	// methods only used by SpeedSim
	void simulateSpeed();
	void basicSpeedSim();
	void initialSpeed();

	// increments and decrements
	void increment(double _amount);
	void decrement(double _amount);
};

