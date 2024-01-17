#include <iostream>
#include <map>
#include "./App.h"

int main() {
	InStreamInput userInput(std::cin);
	std::map<int, IAction*> actions = {};
	App app(userInput, actions, 0);
	app.run();

	return 0;
}
