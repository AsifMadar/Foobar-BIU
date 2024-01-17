#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//interface to the class Userinput
class IUserinput{
    public:
virtual int getFilterSettings(std::vector<int>* settingsVec, int maxIdVal) = 0;
virtual int getUserActionAndURL(int* actionNumber, std::string* url, int max) = 0;

};