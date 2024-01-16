#include <functional>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "./BloomFilter.h"
#include "./UserInput.h"

class App {
	public:
		App(UserInput userInput);
		~App();
		App(const App& other);
		App(App&& other) noexcept;
		App& operator=(const App& other);
		App& operator=(App&& other);
		void run();
		void runNextIteration();

	private:
		void createBloomFilter();

		UserInput userInput;
		BloomFilter* bloomFilter = nullptr;
		std::vector<std::string> blackList = {}; // Will be used to validate suspected false-positives
};
