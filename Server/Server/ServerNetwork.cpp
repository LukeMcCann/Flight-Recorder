#include "StdAfx.h"
#include "ServerNetwork.h"

// Constructor
ServerNetwork::ServerNetwork(void)
{
	WSADATA wsaData;

	// Initialize Sockets
	ListenSocket = INVALID_SOCKET;
	ClientSocket = INVALID_SOCKET;

	// address info for the Server to listen
	struct addrinfo *result = NULL;
	struct addrinfo hints;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		printf("WSAStartup failed, Error: %d\n", iResult);
		exit(1);
	}

	// set the address information
	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = IPPROTO_TCP;   
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);

	if (iResult != 0) {
		printf("getaddrinfo failed, Error: %d\n", iResult);

		WSACleanup();
		exit(1);
	}

	// SOCKET for connecting Clients to Server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);

	if (ListenSocket == INVALID_SOCKET) {
		printf("socket failed, Error: %ld\n", WSAGetLastError());

		freeaddrinfo(result);
		WSACleanup();
		exit(1);
	}

	// Set the mode of the socket to be nonblocking
	u_long iMode = 1;
	iResult = ioctlsocket(ListenSocket, FIONBIO, &iMode);

	if (iResult == SOCKET_ERROR) {
		printf("ioctlsocket failed, Error: %d\n", WSAGetLastError());

		closesocket(ListenSocket);
		WSACleanup();
		exit(1);
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);

	if (iResult == SOCKET_ERROR) {
		printf("bind failed, Error: %d\n", WSAGetLastError());

		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		exit(1);
	}

	
	freeaddrinfo(result); // addrinfo no longer required for result

	// start listening for new clients
	iResult = listen(ListenSocket, SOMAXCONN);

	if (iResult == SOCKET_ERROR) {
		printf("listen failed, Error: %d\n", WSAGetLastError());

		closesocket(ListenSocket);
		WSACleanup();
		exit(1);
	}
}

// destructor
ServerNetwork::~ServerNetwork(void)
{
}

/*
* <subject>
* if a Client is waiting, accepts Client connection
* validates the ClientSocket is not an INVALID_SOCKET
* adds the client to the session id map
* @param id - id of the connecting Client
* </subject>
*/
bool ServerNetwork::acceptClient(unsigned int & id)
{
	ClientSocket = accept(ListenSocket, NULL, NULL);

	if (ClientSocket != INVALID_SOCKET)
	{
		//disable Nagle's Algorithm on the Client's socket
		char value = 1;

		setsockopt(ClientSocket, IPPROTO_TCP, TCP_NODELAY, &value, sizeof(value));
		sessions.insert(pair<unsigned int, SOCKET>(id, ClientSocket));

		return true;
	}

	return false;
}

/*
* <subject>
* checks the client_id is in the table
* receives data from the Client
* @param client_id - id of the sending Client
* @param recbuf - the buffer receiving the data
* </subject>
*/
int ServerNetwork::receiveIncomingData(unsigned int client_id, char * recbuf)
{
	if (sessions.find(client_id) != sessions.end())
	{
		SOCKET curSock = sessions[client_id];
		iResult = NetworkServices::receiveMessage(curSock, recbuf, MAX_PACKET_SIZE);

		if (iResult == 0)
		{
			printf("Connection closed\n");
			closesocket(curSock);
		}

		return iResult;
	}

	return 0;
}


/*
* <subject>
* iterates through SOCKET table
* sends data to all Clients in the table
* @param packets - packets to be sent
* @param totalSize - size of packets being sent
* </subject>
*/
void ServerNetwork::sendAll(char* packets, int totalSize)
{
	SOCKET curSock;

	std::map<unsigned int, SOCKET>::iterator i;
	int iSendResult;

	for (i = sessions.begin(); i != sessions.end(); i++)
	{
		curSock = i->second;
		iSendResult = NetworkServices::sendMessage(curSock, packets, totalSize);

		if (iSendResult == SOCKET_ERROR)
		{
			printf("send failed, Error: %d\n", WSAGetLastError());
			closesocket(curSock);
		}
	}
}
