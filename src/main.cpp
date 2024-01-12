#include <iostream>
#include <vector>
#include "./userInput.h"

enum class Action { Unset, AddURL, CheckURL, };

int main() {
	Action action = Action::Unset;
	std::vector<int>* initialSettingsVec = new std::vector<int>;
	readLineNumbers(std::cin, initialSettingsVec, 2, 3);
	for (int n: *initialSettingsVec) std::cout << n << ", ";
	std::cout << '\n';

	return 0;
}
