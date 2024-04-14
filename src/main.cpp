#include <iostream>
#include <map>
#include "./AddURLToBlacklist.h"
#include "./App.h"
#include "./CheckURLInBlacklist.h"
#include "./Server.h"

int main() {
	runServer();
	return 0;
	InStreamInput userInput(std::cin);
	AddURLToBlacklist action1{};
	CheckURLInBlacklist action2(std::cout);
	std::map<int, IAction*> actions = {{1, &action1}, {2, &action2}};
	App app(&userInput, actions, actions.size());
	app.run();

	return 0;
}
