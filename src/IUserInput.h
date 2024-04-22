#pragma once
#include <string>
#include <vector>

class IUserInput{
    public:
        virtual int getFilterSettings(std::vector<int>* settingsVec, int maxIdVal) = 0;
        virtual int getUserActionAndURL(int* actionNumber, std::string* url, int max) = 0;
};
