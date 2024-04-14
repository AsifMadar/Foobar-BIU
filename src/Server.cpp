#include <arpa/inet.h>
#include <iostream>
#include <netinet/in.h>
#include <stdexcept>
#include <stdio.h>
#include <thread>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include "./Server.h"

Server::Server(int port, int bufferSize): port(port), bufferSize(bufferSize) {
	this->socket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (this->socket < 0) throw std::runtime_error("error creating socket");

	memset(&this->sin, 0, sizeof(this->sin));

	this->sin.sin_family = AF_INET;
	this->sin.sin_addr.s_addr = INADDR_ANY;
	this->sin.sin_port = htons(this->port);
}

Server::~Server() {
	this->stop();
}

void Server::start() {
	int bindResult = bind(this->socket, (struct sockaddr *) &this->sin, sizeof(this->sin));
	if (bindResult < 0) throw std::runtime_error("error binding socket");
	if (listen(this->socket, 5) < 0) throw std::runtime_error("error listening to a socket");

	//while (true) {
		waitForConnection();
	//}
}

void Server::stop() {
	close(this->socket);
}

void Server::waitForConnection() {
	struct sockaddr_in client_sin;
	unsigned int addr_len = sizeof(client_sin);

	int clientSocket = accept(this->socket, (struct sockaddr *) &client_sin, &addr_len);
	if (clientSocket < 0) throw std::runtime_error("error accepting client");

	char address[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &client_sin.sin_addr, address, sizeof(address));
	int port = htons(client_sin.sin_port);
	std::cout << address << ":" << port << std::endl;

	std::thread t(&Server::handleConnection, this, clientSocket);
	// TODO: REMOVE
	t.join();
}

void Server::handleConnection(int clientSocket) {
	char* buffer = new char[this->bufferSize];
	int read_bytes = 0;
	do {
		std::fill_n(buffer, this->bufferSize, 0);
		read_bytes = recv(clientSocket, buffer, this->bufferSize, 0);

		if (read_bytes == 0) break;
		if (read_bytes < 0) throw std::runtime_error("error reading request");

		std::cout << "Client sent: " << buffer << std::endl;

		int sent_bytes = send(clientSocket, buffer, read_bytes, 0);
		if (sent_bytes < 0) throw std::runtime_error("error sending to client");
	} while (true);

	delete [] buffer;

	close(clientSocket);
}
