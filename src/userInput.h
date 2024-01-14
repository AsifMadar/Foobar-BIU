#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int readLineNumbers(std::istream& input, std::vector<int>* iVector, unsigned short minNums = 1, unsigned short maxNums = 0);
int getFilterSettings(std::istream& input, std::vector<int>* settingsVec, int maxIdVal);
int getUserActionAndURL(std::istream& input, int* actionNumber, std::string* url);
