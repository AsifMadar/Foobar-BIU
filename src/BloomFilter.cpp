#include <string>
#include <vector>
#include <functional>
#include "HashFuncs.h"
#include "BloomFilter.h"

using namespace std;

        //Hashing the url and returning index for the array
    int BloomFilter::hashItIn(string url, int i) {
            return hashFunctions[i](url) % bitArray.size();
    }

    // initializing the BloomFilter instance.
    BloomFilter::BloomFilter(int size, const vector<HashFuncs::FuncPointer> hashFunctions) : bitArray(size), hashFunctions(hashFunctions)  { }

    std::vector<bool> BloomFilter::getBitArray() {
        return this->bitArray;
    }

    // @brief Adding the item to the bitArray.
    // @param url The url which gets Hashed and get in the bitArray
    void BloomFilter::addItem(string url) {
        for(int i = 0; i < hashFunctions.size(); i++) {
            int j = hashItIn(url, i);
            bitArray[j] = true;
        }
    }

    //@brief This function checks if the url hashed into the bitArray
    //@param url The array which is checked
    //@return true if in, otherwise false
    bool BloomFilter::getItem(string url) {
        for(int i = 0; i < hashFunctions.size(); i++) {
            int j = hashItIn(url, i);
            if (bitArray[j] == false)
                return false;
        }
        return true;
    }
