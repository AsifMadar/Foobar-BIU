#pragma once
#include <string>
#include <vector>
#include <functional>
#include "HashFuncs.h"

using namespace std;

class BloomFilter {
private:
vector<int> bitArray;
const vector<HashFuncs::FuncPointer> hashFunctions;

    int hashItIn(string url, int i);

    public:
    BloomFilter(int size, const vector<HashFuncs::FuncPointer> hashFunctions);

    std::vector<int> getBitArray();

    void addItem(string url);
    bool getItem(string url);
};