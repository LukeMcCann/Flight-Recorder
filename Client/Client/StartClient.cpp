// main.cpp : Defines the entry point for the console application.
//

// may need #include "stdafx.h" in visual studio
#include "stdafx.h"
#include "Client.h"
#include <WinBase.h>
#include "DataSim.h"

DataSim* data;

void clientLoop(void);
Client * client;

int main()
{
	// initialize the client 
	client = new Client();
	clientLoop();
}

void clientLoop()
{
	while (true)
	{
		client->update();
		Sleep(1000);
	}
}
