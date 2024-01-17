#include <functional>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "./BloomFilter.h"
#include "./FalsePositiveCheck.h"
#include "./HashFuncs.h"
#include "./IAction.h"
#include "./InStreamInput.h"
#include "./IUserInput.h"

class App {
	public:
		App(IUserInput* userInput, std::map<int, IAction*> actions, int maxAction);
		~App();
		App(const App& other);
		App(App&& other) noexcept;
		App& operator=(const App& other);
		App& operator=(App&& other);
		void run();
		void runNextIteration();

	private:
		void createBloomFilter();

		BloomFilter* bloomFilter = nullptr;
		int maxAction;
		std::map<int, IAction*> actions;
		FalsePositiveCheck blackList{};
		IUserInput* userInput;
};
