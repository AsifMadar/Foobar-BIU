#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class UserInput {
	public:
		UserInput(std::istream& input);
		int readLineNumbers(std::vector<int>* iVector, unsigned short minNums = 1, unsigned short maxNums = 0);
		int getFilterSettings(std::vector<int>* settingsVec, int maxIdVal);
		int getUserActionAndURL(int* actionNumber, std::string* url, int max);

	private:
		std::istream& inputStream;
};
