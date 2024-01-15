#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "./HashFuncs.h"
#include "./userInput.h"

enum class Action { Unset, AddURL, CheckURL, };
const int maxValidAction = 2;

// Waiting for BloomFilter.h
/* enum class CheckURLResult { Unset, AddURL, CheckURL, };

CheckURLResult checkURL(BloomFilter* bloomFilter, std::vector<std::string> blackList, std::string url); */

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
				//CheckURLResult checkResult = checkURL(&bloomFilter, &blackList, url);
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
	bool failure = getFilterSettings(std::cin, &settingsVec, HashFuncs::getFuncsNum() + 1) == -1;
	if (failure) throw std::runtime_error("No valid input was provided");

	int bloomBitArrayLength = settingsVec[0];
	settingsVec.erase(settingsVec.begin());
	HashFuncs hashFuncs(settingsVec);
	const std::vector<HashFuncs::FuncPointer>* hashFunctionsVec = hashFuncs.getFuncsVec();

	// Once we have a header file for BloomFilter.cpp, we should change the return type and return the bloom filter
	// return new BloomFilter(bloomBitArrayLength, &hashFunctionsVec);
}
