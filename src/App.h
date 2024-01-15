#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
//#include "./BloomFilter.h"
#include "./UserInput.h"

class App {
	public:
		App(UserInput userInput);
		void run();
		void runNextIteration();

	private:
		UserInput userInput;
		//BloomFilter bloomFilter = NULL;
		bool createBloomFilterRun = false; // Delete after we get BloomFilter
		std::vector<std::string> blackList = {}; // Will be used to validate suspected false-positives
};
