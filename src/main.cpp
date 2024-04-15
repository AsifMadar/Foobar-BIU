#include <iostream>
#include <map>
#include <sstream>
#include <thread>
#include "./AddURLToBlacklist.h"
#include "./App.h"
#include "./CheckURLInBlacklist.h"
#include "./InStreamInput.h"
#include "./Server.h"

#define SERVER_PORT 5555
#define SERVER_BUFFER_SIZE (1024 * 100)

int main() {
	std::stringstream inStream{};
	std::stringstream outStream{};

	InStreamInput userInput(inStream);
	AddURLToBlacklist action1{};
	CheckURLInBlacklist action2(outStream);
	std::map<int, IAction*> actions = {{1, &action1}, {2, &action2}};
	App app(&userInput, actions, actions.size());

	Server::AppInfo appInfo(app, inStream, outStream);
	Server server(SERVER_PORT, SERVER_BUFFER_SIZE, appInfo);
	server.start();

	return 0;
}
