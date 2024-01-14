#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "./hashFuncs.h"
#include "./userInput.h"

enum class Action { Unset, AddURL, CheckURL, };
const int maxValidAction = 2;

void createBloomFilter();

int main() {
	createBloomFilter();
	std::vector<std::string> blackList = {}; // Will be used to validate suspected false-positives

	while (true) { // This is the main loop of the program
		Action action = Action::Unset;
		int actionNumber;
		std::string url;
		bool failure = getUserActionAndURL(std::cin, &actionNumber, &url, maxValidAction + 1) == -1;
		if (failure) throw std::runtime_error("No valid input was provided");
		action = Action(actionNumber);

		switch (action) {
			case Action::AddURL:
				// Implement addURL() first
				//addURL(&bloomFilter, &blackList, url);
				break;

			case Action::CheckURL:
				// Implement checkURL() first
				//CheckResult checkResult = checkURL(&bloomFilter, &blackList, url);
				break;
			
			default:
				break;
		}
	}

	return 0;
}

/// @brief Creates and returns a heap-allocated BloomFilter instance, based on the input from the user
void createBloomFilter() {
	// Get the settings for the bloom filter
	std::vector<int> settingsVec = {};
	bool failure = getFilterSettings(std::cin, &settingsVec, hashFuncs::functionsNum + 1) == -1;
	if (failure) throw std::runtime_error("No valid input was provided");

	int bloomBitArrayLength = settingsVec[0];
	std::vector<hashFuncs::FuncPointer> hashFunctionsVec = {};
	for (int i = 1; i < settingsVec.size(); i++) {
		hashFunctionsVec.push_back(hashFuncs::functions[settingsVec[i] - 1]);
	}

	// Once we have a header file for BloomFilter.cpp, we should change the return type and return the bloom filter
	// return new BloomFilter(bloomBitArrayLength, hashFunctionsVec);
}
