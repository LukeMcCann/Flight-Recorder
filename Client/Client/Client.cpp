#include "StdAfx.h"
#include "Client.h"
#include "DataSim.h"

DataSim* sim;

Client::Client(void)
{

	network = new ClientNetwork();

	// send init packet
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	packet.packet_type = INIT_CONNECTION;

	packet.serialize(packet_data);

	NetworkServices::sendMessage(network->ConnectSocket, packet_data, packet_size);
}


Client::~Client(void)
{
}

void Client::sendActionPackets()
{
	// send action packet
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	// double values
	packet.speed = sim->output(1);
	packet.fuel = 0.00;
	packet.temp = 0.00;
	// float values
	packet.altitude = 0.00;
	packet.longitude = 123456;
	packet.latitude = 123456;

	packet.packet_type = DATA_EVENT;
	packet.serialize(packet_data);

	NetworkServices::sendMessage(network->ConnectSocket, packet_data, packet_size);
}

void Client::update()
{
	Packet packet;
	int data_length = network->receivePackets(network_data);

	if (data_length <= 0)
	{
		//no data recieved
		return;
	}

	int i = 0;
	while (i < (unsigned int)data_length)
	{
		packet.deserialize(&(network_data[i]));
		i += sizeof(Packet);

		switch (packet.packet_type) {

		case DATA_EVENT:

			printf("client received action event packet from server\n");

			sendActionPackets();

			break;

		default:

			printf("error in packet types\n");

			break;
		}
	}
}
