#pragma once
#include <winsock2.h>
#include <Windows.h>
#include "NetworkServices.h"
#include <ws2tcpip.h>
#include <map>
#include "NetworkData.h"
using namespace std;
#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "6881" 

class ServerNetwork
{
public:
	ServerNetwork(void);
	~ServerNetwork(void);

	void sendAll(char * packets, int totalSize); // send to all Clients
	int receiveIncomingData(unsigned int client_id, char * recvbuf); 
	bool acceptClient(unsigned int & id); // accept new connecting Client

	SOCKET ListenSocket;
	SOCKET ClientSocket;

	int iResult;
	std::map<unsigned int, SOCKET> sessions; // table to map each client's socket
};
