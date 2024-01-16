#include <stdexcept>
#include <string>
#include <vector>
#include "./App.h"
#include "./BloomFilter.h"
#include "./HashFuncs.h"
#include "./UserInput.h"

enum class Action { Unset, AddURL, CheckURL, };
static const int maxValidAction = 2;

/// @param userInput A UserInput instance to read the input from
App::App(UserInput userInput): userInput(userInput) {};

App::~App() {
	delete this->bloomFilter;
};
App::App(const App& other): bloomFilter(other.bloomFilter), userInput(other.userInput) {}
App::App(App&& other) noexcept: bloomFilter(std::exchange(other.bloomFilter, nullptr)), userInput(other.userInput) {}
App& App::operator=(const App& other) {
	*this = App(other);
	return *this;
}
App& App::operator=(App&& other) {
	std::swap(this->bloomFilter, other.bloomFilter);
	return *this;
}

/// @brief Creates and assigns a heap-allocated BloomFilter instance, based on the input from the user
void App::createBloomFilter() {
	// Get the settings for the bloom filter
	std::vector<int> settingsVec = {};
	bool failure = this->userInput.getFilterSettings(&settingsVec, HashFuncs::getFuncsNum() + 1) == -1;
	if (failure) throw std::runtime_error("No valid input was provided");

	// Create the bloom filter
	int bloomBitArrayLength = settingsVec[0];
	settingsVec.erase(settingsVec.begin());
	HashFuncs hashFuncs(settingsVec);
	const std::vector<HashFuncs::FuncPointer>* hashFunctionsVec = hashFuncs.getFuncsVec();

	this->bloomFilter = new BloomFilter(bloomBitArrayLength, *hashFunctionsVec);
}

/// @brief Runs the next iteration of the main program loop
void App::runNextIteration() {
	if (this->bloomFilter == nullptr) this->createBloomFilter();

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

