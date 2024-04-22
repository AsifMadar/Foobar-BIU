#include <arpa/inet.h>
#include <exception>
#include <iostream>
#include <mutex>
#include <netinet/in.h>
#include <sstream>
#include <stdexcept>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sys/socket.h>
#include <thread>
#include <unistd.h>
#include "./App.h"

class Server {
	public:
		class AppInfo {
			public:
				AppInfo(App& app, std::stringstream& AppInStream, std::stringstream& AppOutStream):
					app(app), AppInStream(AppInStream), AppOutStream(AppOutStream) {};
				AppInfo(const AppInfo& other):
					app(other.app), AppInStream(other.AppInStream), AppOutStream(other.AppOutStream) {};

				friend Server;

			private:
				App& app;
				/// The stream that goes *into* `app` is an *out* stream from the server perspective
				std::stringstream& AppInStream;
				/// The stream that goes *out* of `app` is an *in* stream from the server perspective
				std::stringstream& AppOutStream;
				std::mutex mutex{};
		};

		Server(int port, int bufferSize, AppInfo appInfo);
		~Server();
		void start();
		void stop();

	private:
		void handleConnection(int clientSocket);
		void waitForConnection();

		AppInfo appInfo;
		int bufferSize;
		int port;
		int socket;
		struct sockaddr_in sin;
};
