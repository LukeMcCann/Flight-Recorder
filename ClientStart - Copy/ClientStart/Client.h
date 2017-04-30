#pragma once
#include <winsock2.h>
#include <Windows.h>
#include "ClientNetwork.h"
#include "NetworkData.h"
#include <string>

class Client
{
public:
	Client(void);
	~Client(void);

	void sendActionPackets(int _flightid, std::string _planeid, double _speed,
		double _fuel, double _temp, float _alt, float _lat, float _lon);

	void update(int _flightid, std::string _planeid, double _speed,
		double _fuel, double _temp, float _alt, float _lat, float _lon);

	ClientNetwork* network;

	// void sendActionPackets(void);

	char network_data[MAX_PACKET_SIZE];

	// void update();

private:

	int id = 0;
};

