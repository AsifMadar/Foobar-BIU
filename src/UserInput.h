#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

class UserInput {
	public:
		UserInput(std::istream& input);
		int readLineNumbers(std::vector<int>* iVector, unsigned short minNums, unsigned short maxNums);
		int getFilterSettings(std::vector<int>* settingsVec, int maxIdVal);
		int getUserActionAndURL(int* actionNumber, std::string* url, int max);

	private:
		std::istream& inputStream;
};
