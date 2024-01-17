#include <functional>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>
#include "./IAction.h"
#include "./BloomFilter.h"
#include "./HashFuncs.h"
#include "./InStreamInput.h"
#include "./FalsePositiveCheck.h"

class App {
	public:
		App(InStreamInput userInput, std::map<int, IAction*> actions, int maxAction);
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
		std::vector<std::string> blackList = {}; // Will be used to validate suspected false-positives
		InStreamInput userInput;
};
