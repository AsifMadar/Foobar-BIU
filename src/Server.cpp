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
#include "./Server.h"

#define DEBUG 1
#if (DEBUG == 1)
#define QUIT_COMMAND "!quit"
#endif

/// @brief Creates a new Server instance
/// @param port The port to listen on
/// @param bufferSize The size of the buffer used for communicating with clients
/// @param app An instance of `App` the server will pass requests to
Server::Server(int port, int bufferSize, App& app): port(port), bufferSize(bufferSize), app(app) {
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

/// @brief Starts the server, i.e. listens for requests on the specified port
void Server::start() {
	int bindResult = bind(this->socket, (struct sockaddr *) &this->sin, sizeof(this->sin));
	if (bindResult < 0) throw std::runtime_error("error binding socket");
	if (listen(this->socket, 5) < 0) throw std::runtime_error("error listening to a socket");

	while (true) waitForConnection();
}

/// @brief Stops the server, i.e. unbinds the specified port
void Server::stop() {
	close(this->socket);
}

/// @brief Waits for a client to connect to the server, and creates a thread to handle that client
void Server::waitForConnection() {
	struct sockaddr_in client_sin;
	unsigned int addr_len = sizeof(client_sin);

	int clientSocket = accept(this->socket, (struct sockaddr *) &client_sin, &addr_len);
	if (clientSocket < 0) throw std::runtime_error("error accepting client");

	char address[INET_ADDRSTRLEN];
	inet_ntop(AF_INET, &client_sin.sin_addr, address, sizeof(address));
	int port = htons(client_sin.sin_port);
	std::cout << address << ":" << port << " connected" << std::endl;

	std::thread t(&Server::handleConnection, this, clientSocket);
	t.detach();
}

/// @brief Handles the connection with a single client
/// @param clientSocket The socket the client is connected on
void Server::handleConnection(int clientSocket) {
	char* buffer = new char[this->bufferSize];
	int read_bytes = 0;
	do {
		std::fill_n(buffer, this->bufferSize, 0);
		read_bytes = recv(clientSocket, buffer, this->bufferSize, 0);

		if (read_bytes == 0) break;
		if (read_bytes < 0) throw std::runtime_error("error reading request");

		std::cout << "Client sent: " << buffer << std::endl;

		#if (DEBUG == 1)
			if (!strcmp(buffer, QUIT_COMMAND)) {
				std::cout << "Quit command received; Terminating program." << std::endl;
				this->stop();
				std::terminate();
			}
		#endif

		int sent_bytes = send(clientSocket, buffer, read_bytes, 0);
		if (sent_bytes < 0) throw std::runtime_error("error sending to client");
	} while (true);

	delete [] buffer;

	close(clientSocket);
}
