#pragma once
#include <winsock2.h>
#include <Windows.h>
#include "ClientNetwork.h"
#include "NetworkData.h"

class Client
{
public:
	Client(void);
	~Client(void);

	ClientNetwork* network;

	void sendActionPackets();

	char network_data[MAX_PACKET_SIZE];

	void update();
};

