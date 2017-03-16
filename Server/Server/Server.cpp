#include "StdAfx.h"
#include "Server.h"

unsigned int Server::client_id;

Server::Server(void)
{
	client_id = 0;
	network = new ServerNetwork(); // setup to listen
}

Server::~Server(void)
{
}

/*
* <subject>
* if Client is connected
* start receiving from clients
* </subject>
*/
void Server::update()
{
	if (network->acceptClient(client_id))
	{
		printf("client %d has been connected to the server\n", client_id);
		client_id++;
	}

	receiveFromClients();
}

/*
* <subject>
* iterates through all Clients
* starts receiving from Clients
* switch based on packet type: INIT_CONNECTION, DATA_EVENT
* </subject>
*/
void Server::receiveFromClients()
{

	Packet packet;
	std::map<unsigned int, SOCKET>::iterator i;

	for (i = network->sessions.begin(); i != network->sessions.end(); i++)
	{
		int data_length = network->receiveIncomingData(i->first, network_data);

		if (data_length <= 0) // no data received
		{
			continue;
		}

		int i = 0;
		while (i < (unsigned int)data_length)
		{
			packet.deserialize(&(network_data[i]));
			i += sizeof(Packet);

			switch (packet.packet_type) {

			case INIT_CONNECTION:

				printf("server received initial packet from client\n");
				sendActionPackets();

				break;

			case DATA_EVENT:

				printf("server received action event packet from client\n");
				printf("Packet contained:\n");
				printf("mach-speed: %.7f\n", packet.speed);
				printf("knots-speed: %d", 450);
				printf("fuel: %.1f\n", packet.fuel);
				printf("engine-temp: %.1f\n", packet.temp);
				printf("altitude: %.1f\n", packet.altitude);
				printf("GPS: longitude %.1f, latitude %.f\n", packet.longitude, packet.latitude);
				printf("\n");

				sendActionPackets(); // confirm receipt to client

				break;

			default:

				printf("error in packet types\n");

				break;
			}
		}
	}
}

/*
* <subject>
* serialize and sends DATA_EVENT packets to client
* </subject>
*/
void Server::sendActionPackets()
{
	const unsigned int packet_size = sizeof(Packet);
	char packet_data[packet_size];

	Packet packet;
	packet.packet_type = DATA_EVENT;

	packet.serialize(packet_data);
	network->sendAll(packet_data, packet_size);
}