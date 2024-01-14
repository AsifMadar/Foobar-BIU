#include <string>
#include <vector>
#include <functional>
#include "hashFuncs.h"

using namespace std;

class BloomFilter {

private:
vector<int> bitArray;
vector<hashFuncs::FuncPointer> hashFunctions;

    int hashItIn(string url, int i) {
            return hashFunctions[i](url) % bitArray.size();
        }

    public:
    // initializing the BloomFilter instance.
    BloomFilter(int size, vector<hashFuncs::FuncPointer> hashFunctions) : bitArray(size), hashFunctions(hashFunctions)  { }

    std::vector<int> getBitArray() {
        return this->bitArray;
    }

    // Adding the item to the blacklist.
    void addItem(string url) {
        for(int i = 0; i < hashFunctions.size(); i++) {
            int j = hashItIn(url, i);
            bitArray[j] = 1;
        }
    }
    bool getItem(string url) {
        for(int i = 0; i < hashFunctions.size(); i++) {
            int j = hashItIn(url, i);
            if (bitArray[j] == 0)
                return false;
        }
        return true;
    }
};