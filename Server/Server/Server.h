#pragma once
#include "ServerNetwork.h"
#include "NetworkData.h"

class Server
{

public:
	Server(void);
	~Server(void);


	void update();
	void sendActionPackets();
	void receiveFromClients();

private:

	ServerNetwork* network;

	static unsigned int client_id; // ID's for connecting Client : table in ServerNetwork
	char network_data[MAX_PACKET_SIZE]; // data buffer
};
