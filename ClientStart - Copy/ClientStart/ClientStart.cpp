// main.cpp : Defines the entry point for the console application.
//

// may need #include "stdafx.h" in visual studio
#include "stdafx.h"
#include "Client.h"
#include <WinBase.h>
#include "Speedometer.h"
#include "SpeedSim.h"

void clientLoop(int _flightid, std::string _planeid, double _speed,
	double _fuel, double _temp, float _alt, float _lat, float _lon);

void initialise();

Client * client;
Speedometer * speedometer;
SpeedSim * speedsim;

int main()
{
	// start();
	while (true)
	{
		speedsim = new SpeedSim();
		speedsim->start();

		printf("Speed: %.6f", speedsim->getSpeed());
		Sleep(1000);
	}

}

void start()
{
	initialise();
	// clientLoop();
}

void initialise()
{
	client = new Client();
	speedometer = new Speedometer();
}

void clientLoop(int _flightid, std::string _planeid, double _speed,
	double _fuel, double _temp, float _alt, float _lat, float _lon)
{
	while (true)
	{
		client->update(_flightid, _planeid, _speed, _fuel, _temp, _alt, _lat, _lon);
		Sleep(1000);
	}
}