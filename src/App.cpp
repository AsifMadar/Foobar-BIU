#include <stdexcept>
#include <string>
#include <vector>
#include "./App.h"
//#include "./BloomFilter.h"
#include "./HashFuncs.h"
#include "./UserInput.h"

enum class Action { Unset, AddURL, CheckURL, };
static const int maxValidAction = 2;

/// @param userInput A UserInput instance to read the input from
App::App(UserInput userInput): userInput(userInput) {};

/// @brief Creates and returns a heap-allocated BloomFilter instance, based on the input from the user
/// @param userInput A UserInput instance to read the settings from
void createBloomFilter(UserInput& userInput) {
	// Get the settings for the bloom filter
	std::vector<int> settingsVec = {};
	bool failure = userInput.getFilterSettings(&settingsVec, HashFuncs::getFuncsNum() + 1) == -1;
	if (failure) throw std::runtime_error("No valid input was provided");

	int bloomBitArrayLength = settingsVec[0];
	settingsVec.erase(settingsVec.begin());
	HashFuncs hashFuncs(settingsVec);
	const std::vector<HashFuncs::FuncPointer>* hashFunctionsVec = hashFuncs.getFuncsVec();

	// Once we have a header file for BloomFilter.cpp, we should change the return type and return the bloom filter
	// return new BloomFilter(bloomBitArrayLength, &hashFunctionsVec);
}

/// @brief Runs the next iteration of the main program loop
void App::runNextIteration() {
	// Waiting for BloomFilter.h
	if (!this->createBloomFilterRun /* this->bloomFilter == NULL */) {
		createBloomFilter(this->userInput);
		this->createBloomFilterRun = true;
	}
	Action action = Action::Unset;
	int actionNumber;
	std::string url;
	bool failure = this->userInput.getUserActionAndURL(&actionNumber, &url, maxValidAction + 1) == -1;
	if (failure) throw std::runtime_error("No valid input was provided");
	action = Action(actionNumber);

	switch (action) {
		case Action::AddURL:
			// Implement addURL() first
			//addURL(&bloomFilter, &blackList, url);
			break;

		case Action::CheckURL:
			// Implement checkURL() first
			//CheckURLResult checkResult = checkURL(&bloomFilter, &blackList, url);
			break;
		
		default:
			break;
	}
}

/// @brief Runs the main program loop
void App::run() {
	while (true) App::runNextIteration();
}

