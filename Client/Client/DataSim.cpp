#include "stdafx.h"
#include "DataSim.h"

Plane p;
Speedometer speed;

Plane* plane = &p;
Sensor* speedsensor = &speed;

DataSim::DataSim()
{
}


DataSim::~DataSim()
{
}

T DataSim::output(int num)
{
	if (num == NULL) return 0;

	speedsim();

	switch (num)
	{
	case 1:
		return speedsensor->getSpeed();
		break;
	case 2:
		return 0.00;//temp
		break;
	case 3:
		return 0.00; //fuel
		break;
	case 4:
		return 0.00; // alt
		break;
	case 5:
		return 0.00; // long
		break;
	case 6:
		return 0.00; // lat
		break;
	default:
		return 0;
		break;
	}
}
void DataSim::speedsim()
{
	try {
		if (speedsensor->getSpeed() >= plane->getMaxSpeed() - 0.0149984)
		{
			speedsensor->decrement(0.00299968);

			Sleep(1000);
		}
		else if (speedsensor->getSpeed() <= plane->getMinSpeed())
		{
			speedsensor->decrement(0.00299968);

			Sleep(1000);
		}
		else {
			int random = r->genRandom(0, 10);
			if (random < 5 && random > 0)
			{
				speedsensor->increment(0.00149984);

				Sleep(1000);

			}
			else
			{
				speedsensor->decrement(0.00149984);

				Sleep(1000);
			}
		}
	}
	catch (...)
	{
		exit(0);
	}
}
