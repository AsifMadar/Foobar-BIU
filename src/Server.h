#include <arpa/inet.h>
#include <exception>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include "./App.h"

class Server {
	public:
		Server(int port, int bufferSize, App& app);
		~Server();
		void start();
		void stop();

	private:
		void handleConnection(int clientSocket);
		void waitForConnection();

		App& app;
		int bufferSize;
		int port;
		int socket;
		struct sockaddr_in sin;
};
