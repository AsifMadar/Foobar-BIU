#include <string>
#include <vector>
#include <functional>
#include "HashFuncs.h"
#include "BloomFilter.h"

using namespace std;


    int BloomFilter::hashItIn(string url, int i) {
            return hashFunctions[i](url) % bitArray.size();
        }

    // initializing the BloomFilter instance.
    BloomFilter::BloomFilter(int size, const vector<HashFuncs::FuncPointer> hashFunctions) : bitArray(size), hashFunctions(hashFunctions)  { }

    std::vector<int> BloomFilter::getBitArray() {
        return this->bitArray;
    }

    // Adding the item to the blacklist.
    void BloomFilter::addItem(string url) {
        for(int i = 0; i < hashFunctions.size(); i++) {
            int j = hashItIn(url, i);
            bitArray[j] = 1;
        }
    }
    bool BloomFilter::getItem(string url) {
        for(int i = 0; i < hashFunctions.size(); i++) {
            int j = hashItIn(url, i);
            if (bitArray[j] == 0)
                return false;
        }
        return true;
    }