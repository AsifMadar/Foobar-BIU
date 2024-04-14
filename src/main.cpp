#include <iostream>
#include <map>
#include "./AddURLToBlacklist.h"
#include "./App.h"
#include "./CheckURLInBlacklist.h"
#include "./Server.h"

#define SERVER_PORT 5555
#define SERVER_BUFFER_SIZE (1024 * 100)

int main() {
	Server server(SERVER_PORT, SERVER_BUFFER_SIZE);
	server.start();
	server.stop();
	return 0;
	InStreamInput userInput(std::cin);
	AddURLToBlacklist action1{};
	CheckURLInBlacklist action2(std::cout);
	std::map<int, IAction*> actions = {{1, &action1}, {2, &action2}};
	App app(&userInput, actions, actions.size());
	app.run();

	return 0;
}
