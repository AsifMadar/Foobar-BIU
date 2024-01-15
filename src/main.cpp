#include <iostream>
#include "./App.h"

int main() {
	UserInput userInput(std::cin);
	App app(userInput);
	app.run();

	return 0;
}
