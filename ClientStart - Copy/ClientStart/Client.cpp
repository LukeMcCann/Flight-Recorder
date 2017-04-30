#include "StdAfx.h"
#include "Client.h"

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

void Client::sendActionPackets(int _flightid, std::string _planeid, double _speed,
	double _fuel, double _temp, float _alt, float _lat, float _lon)
{
	// send action packet
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	// plane data
	packet.flightid = _flightid;
	packet.planeid = _planeid;
	// double values
	packet.speed = _speed;
	packet.fuel = _fuel;
	packet.temp = _temp;
	// float values
	packet.altitude = _alt;
	packet.longitude = _lat;
	packet.latitude = _lon;

	packet.packet_type = DATA_EVENT;
	packet.serialize(packet_data);

	NetworkServices::sendMessage(network->ConnectSocket, packet_data, packet_size);
}

void Client::update(int _flightid, std::string _planeid, double _speed,
	double _fuel, double _temp, float _alt, float _lat, float _lon)
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

			sendActionPackets(_flightid, _planeid, _speed, _fuel, _temp, _alt, _lat, _lon);

			break;

		default:

			printf("error in packet types\n");

			break;
		}
	}
}
