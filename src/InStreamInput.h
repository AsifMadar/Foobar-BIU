#pragma once
#include <istream>
#include <sstream>
#include <string>
#include <vector>
#include "./IUserInput.h"

class InStreamInput: public IUserInput {
	public:
		InStreamInput(std::istream& input);
		int readLineNumbers(std::vector<int>* iVector, unsigned short minNums = 1, unsigned short maxNums = 0);
		int getFilterSettings(std::vector<int>* settingsVec, int maxIdVal);
		int getUserActionAndURL(int* actionNumber, std::string* url, int max);

	private:
		std::istream& inputStream;
};
