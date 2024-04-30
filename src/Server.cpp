#include "./Server.h"

#define DEBUG 0
#if (DEBUG == 1)
#define QUIT_COMMAND "!quit"
#endif

/// @brief Creates a new Server instance
/// @param port The port to listen on
/// @param bufferSize The size of the buffer used for communicating with clients
/// @param appInfo A struct containing the app itself and ways to interact with it
Server::Server(int port, int bufferSize, AppInfo appInfo): port(port), bufferSize(bufferSize), appInfo(appInfo) {
	// Create socket
	this->socket = ::socket(AF_INET, SOCK_STREAM, 0);
	if (this->socket < 0) throw std::runtime_error("error creating socket");

	// Allow reusing the socket
	const int enable = 1;
	if (setsockopt(this->socket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
		throw std::runtime_error("setsockopt(SO_REUSEADDR) failed");

	#ifdef SO_REUSEPORT
		if (setsockopt(this->socket, SOL_SOCKET, SO_REUSEPORT, &enable, sizeof(int)) < 0) 
			throw std::runtime_error("setsockopt(SO_REUSEPORT) failed");
	#endif

	// Initialize `sin` info
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
	char* requestBuffer = new char[this->bufferSize];

	do {
		// Receive message from client
		std::fill_n(requestBuffer, this->bufferSize, 0);
		int msgLen = recv(clientSocket, requestBuffer, this->bufferSize, 0);

		if (msgLen == 0) break;
		if (msgLen < 0) throw std::runtime_error("error reading request");

		std::cout << "Client sent: " << requestBuffer << std::endl;

		#if (DEBUG == 1)
			if (!strcmp(requestBuffer, QUIT_COMMAND)) {
				std::cout << "Quit command received; Terminating program." << std::endl;
				close(clientSocket);
				this->stop();
				return std::terminate();
			}
		#endif

		// Acquire a lock on the app and its streams
		std::unique_lock<std::mutex> lock(this->appInfo.mutex, std::defer_lock);
		lock.lock();

		// Prepare the input for the app
		this->appInfo.AppInStream.str("");
		this->appInfo.AppInStream.clear();
		this->appInfo.AppInStream.write(requestBuffer, msgLen);
		this->appInfo.AppOutStream.str("");
		this->appInfo.AppOutStream.clear();
		std::string responseStr;

		// Pass message to app
		try {
			this->appInfo.app.runNextIteration();
			std::getline(this->appInfo.AppOutStream, responseStr);
		} catch (const std::runtime_error& e) {
			responseStr = e.what();
			std::cout << "Error: " << responseStr << "." << std::endl;
		}

		// Release the lock on the app and its streams
		lock.unlock();

		// Respond to client with the result
		if (responseStr.length() == 0) responseStr = "OK";
		int sent_bytes = send(clientSocket, responseStr.c_str(), responseStr.length(), 0);
		if (sent_bytes < 0) throw std::runtime_error("error sending to client");
	} while (true);

	delete [] requestBuffer;

	close(clientSocket);
}
