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
#include "stdafx.h"
#include "SpeedSim.h"


SpeedSim::SpeedSim()
{
	setMaxSpeed(0.749919); // 500 knots
	setMinSpeed(0.682426); // 450 knots

	random = new RandomGenerator();
}

SpeedSim::SpeedSim(double _minS, double _maxS)
{
	setMaxSpeed(0.749919); // 500 knots
	setMinSpeed(0.682426); // 450 knots

	random = new RandomGenerator();
	
}


SpeedSim::~SpeedSim()
{
}

void SpeedSim::start()
{
	if (firstRun = true) { initialSpeed(); firstRun = false; }

	simulateSpeed();
}

// <subject>
// modified speedSim
// slightly more complex speedSim
// has a chance to increase or decrease
// faster, also is aware of max and min speeds
// and attempts to balance the speed out
// </subject>
void SpeedSim::simulateSpeed()
{
	if (getSpeed() < getMaxSpeed()
		&& getSpeed() > getMinSpeed())
	{
		int x = random->genRandom(0, 10);

		if (x > 5)
		{
			basicSpeedSim();
		}
		else
		{
			if (x % 2 == 0)
			{
				increment(0.002999);
			}
			else
			{
				decrement(0.002999);
			}
		}
	}

	else if (getSpeed() >= (getMaxSpeed() - 0.014998))
	{
		decrement(0.002999);
	}

	else if (getSpeed() <= (getMinSpeed() + 0.014998))
	{
		increment(0.002999);
	}
}

// <subject>
// basic speed simulation
// even chance to increase
// or decrease in speed
// </subject>
void SpeedSim::basicSpeedSim()
{
	int x = random->genRandom(0, 10);

	try
	{
		if (x > 5)
		{
			increment(0.001499);
		}
		else
		{
			decrement(0.001499);
		}
	}
	catch (...)
	{
		printf("Error: SpeedSim::basicSpeedSim Failed!");
	}
}


// <subject>
// initialises the speed 
// to a realistic variable
// allows for diversity between starting speeds
// </subject>
void SpeedSim::initialSpeed()
{
	int x = random->genRandom(0, 10);

	try
	{
		switch (x)
		{
		case 0:
		case 1:
		case 2:

			speed = 0.674927;
			break;

		case 3:
		case 4:
		case 5:

			speed = 0.677927;
			break;

		case 6:
		case 7:
		case 8:

			speed = 0.874406;
			break;

		case 9:
		case 10:

			speed = 0.716923;
			break;

		default:

			speed = 0.712423;
			break;
		}
	}
	catch (...)
	{
		printf("Error: SpeedSim::initialSpeed Failed!");
	}
}



// increments and decrements
void SpeedSim::increment(double _amount)
{
	speed += _amount;
}

void SpeedSim::decrement(double _amount)
{
	speed -= _amount;
}


// getters and setters
double SpeedSim::getSpeed(void)
{
	return speed;
}

void SpeedSim::setSpeed(double _speed)
{
	speed = _speed;
}

// min/max - getters and setters
double SpeedSim::getMinSpeed(void)
{
	return MIN_SAFE_SPEED;
}

void SpeedSim::setMinSpeed(double _speed)
{
	MIN_SAFE_SPEED = _speed;
}

double SpeedSim::getMaxSpeed()
{
	return MAX_SAFE_SPEED;
}

void SpeedSim::setMaxSpeed(double _speed)
{
	MAX_SAFE_SPEED = _speed;
}