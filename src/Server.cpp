#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <stdio.h>
#include <thread>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_PORT 5555
#define SERVER_BUFFER_SIZE (1024 * 100)

void handleConnection(int client_sock) {
	char* buffer = new char[SERVER_BUFFER_SIZE];
	int read_bytes = 0;
	do {
		read_bytes = recv(client_sock, buffer, SERVER_BUFFER_SIZE, 0);

		if (read_bytes == 0) break;
		if (read_bytes < 0) throw std::runtime_error("error reading request");

		std::cout << "Client sent: " << buffer << std::endl;

		int sent_bytes = send(client_sock, buffer, read_bytes, 0);
		if (sent_bytes < 0) throw std::runtime_error("error sending to client");
	} while (true);

	delete [] buffer;

	close(client_sock);
}

void waitForConnection(int serverSocket) {
	struct sockaddr_in client_sin;
	unsigned int addr_len = sizeof(client_sin);

	int client_sock = accept(serverSocket, (struct sockaddr *) &client_sin, &addr_len);
	if (client_sock < 0) throw std::runtime_error("error accepting client");

	char address[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &client_sin.sin_addr, address, sizeof(address));
	int port = htons(client_sin.sin_port);
	std::cout << address << ":" << port << std::endl;

	std::thread t(handleConnection, client_sock);
}

void runServer() {
	int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (serverSocket < 0) throw std::runtime_error("error creating socket");

	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));

	sin.sin_family = AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_port = htons(SERVER_PORT);

	int bindResult = bind(serverSocket, (struct sockaddr *) &sin, sizeof(sin));
	if (bindResult < 0) throw std::runtime_error("error binding socket");
	if (listen(serverSocket, 5) < 0) throw std::runtime_error("error listening to a socket");

	while (true) {
		waitForConnection(serverSocket);
	}

	close(serverSocket);
}
