#include <iostream>
#include <map>
#include <thread>
#include "./AddURLToBlacklist.h"
#include "./App.h"
#include "./CheckURLInBlacklist.h"
#include "./Server.h"

#define SERVER_PORT 5555
#define SERVER_BUFFER_SIZE (1024 * 100)

int main() {
	InStreamInput userInput(std::cin);
	AddURLToBlacklist action1{};
	CheckURLInBlacklist action2(std::cout);
	std::map<int, IAction*> actions = {{1, &action1}, {2, &action2}};
	App app(&userInput, actions, actions.size());

	Server server(SERVER_PORT, SERVER_BUFFER_SIZE, app);
	server.start();

	return 0;
}
