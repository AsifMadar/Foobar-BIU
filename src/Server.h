#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

class Server {
	public:
		Server(int port, int bufferSize);
		~Server();
		void start();
		void stop();

	private:
		void handleConnection(int clientSocket);
		void waitForConnection();

		int bufferSize;
		int port;
		int socket;
		struct sockaddr_in sin;
};
