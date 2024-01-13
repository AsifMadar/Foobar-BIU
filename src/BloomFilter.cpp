#include <string>
#include <vector>
#include <functional>

using namespace std;

class BloomFilter {

private:
int numOfHashesFirstFun;
int numOfHashesSecondFun;
vector<int> bitArray;
hash<string> hashFunc;

    int hashItIn(int hashTimes, string url, bool secondHashFun) {
            int value;
            for(int i = 0; i < hashTimes; i++ ) {
                if (i == 0) { //for the first time to enable us to loop how much time we want
                    value = hashFunc(url);
                }
                else {
                value = hashFunc(to_string(value)); //Now we can hash the value again and again
                }
                if (secondHashFun) {//using the second hash function based the first one
                    value *=31;
                }
            
            return value % bitArray.size();
        }
    }

    public:
    // initializing the BloomFilter instance.
    BloomFilter(int size, int numOfHashesFirstFun, int numOfHashesSecondFun) : bitArray(size),  numOfHashesFirstFun(numOfHashesFirstFun), numOfHashesSecondFun(numOfHashesSecondFun) { }

    std::vector<int> getBitArray() {
        return this->bitArray;
    }

    int getNumOfHashesFirstFun() {
        return this->numOfHashesFirstFun;
    }

    int getNumOfHashesSecondFun() {
        return this->numOfHashesSecondFun;
    }

    // Adding the item to the blacklist.
    void addItem(string url) {
        int FirstFuncUrlValue = hashItIn(numOfHashesFirstFun, url, false); //calls for a method returns the int value after hashing times as requested
        bitArray[FirstFuncUrlValue] = 1;
        if (numOfHashesSecondFun != 0) { //checks if we need to use the other function
            int secondFuncUrlValue = hashItIn(numOfHashesSecondFun, url, true);
            bitArray[secondFuncUrlValue] = 1;
        } // initialize 1 in the dedicated place in the array.
    }
    bool getItem(string url) {
        int FirstFuncUrlValue = hashItIn(numOfHashesFirstFun, url, false); //calls for a method returns the int value after hashing times as requested
        if (numOfHashesSecondFun != 0) { //checks if we need to use the other function
            int secondFuncUrlValue = hashItIn(numOfHashesSecondFun, url, true);
            return bitArray[FirstFuncUrlValue] == 1 && bitArray[secondFuncUrlValue] == 1;
    }
        return bitArray[FirstFuncUrlValue] == 1; //If there's no second hash function
    }
};