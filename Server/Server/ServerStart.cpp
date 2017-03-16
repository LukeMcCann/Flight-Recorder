// main.cpp : Defines the entry point for the console application.
//

// may need #include "stdafx.h" in visual studio
#include "stdafx.h"
#include "Server.h"
#include <WinBase.h>


void serverLoop();
Server * server;

int main()
{
	server = new Server();
	serverLoop();

}
void serverLoop()
{
	while (true)
	{
		server->update();
		Sleep(1000); // update every 5 minutes
	}
}


