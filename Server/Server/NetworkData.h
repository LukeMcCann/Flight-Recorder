#pragma once
#include <string.h>

#define MAX_PACKET_SIZE 1000000

enum PacketTypes {
	INIT_CONNECTION = 0,
	DATA_EVENT = 1,
};


struct Packet {

	unsigned int packet_type;

	double speed;
	double temp;
	double fuel;

	float altitude;
	float longitude;
	float latitude;

	void serialize(char * data) {
		memcpy(data, this, sizeof(Packet));
	}

	void deserialize(char * data) {
		memcpy(this, data, sizeof(Packet));
	}
};