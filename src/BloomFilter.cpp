#include <string>
#include <vector>
#include <functional>
#include <iostream>

using namespace std;

class BloomFilter {

private:
int numOfHashesFirstFun;
int numOfHashesSecondFun;
vector<int> bitArray;
hash<string> stringFirstHashFun;
hash<string> stringSecondHashFun;

    int hashItIn(int hashTimes, string url, hash<string> hashFun, bool secondHashFun) {
            int value = hashFun(url); //Starting the hashing here, because we need to hash more then one time
            if (secondHashFun) { 
                    value *=31;
                }
            for(int i = 0; i < hashTimes - 1; i++ ) {//We hashed once
                value = hashFun(to_string(value)); //Now we can hash the value again and again
                if (secondHashFun) { //Use the second hash function because we don't get different function using hash<string>
                    value *=31;
                }
                }
            return value % bitArray.size();
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
        int FirstFuncUrlValue = hashItIn(numOfHashesFirstFun, url, stringFirstHashFun, false); //calls for a method returns the int value after hashing times as requested
        bitArray[FirstFuncUrlValue] = 1;
        cout << FirstFuncUrlValue << endl;
        if (numOfHashesSecondFun != 0) { //checks if we need to use the other function
            int secondFuncUrlValue = hashItIn(numOfHashesSecondFun, url, stringSecondHashFun, true);
            bitArray[secondFuncUrlValue] = 1;
                    cout << secondFuncUrlValue << endl;
        } // initialize 1 in the dedicated place in the array.
    }
    bool getItem(string url) {
        int FirstFuncUrlValue = hashItIn(numOfHashesFirstFun, url, stringFirstHashFun, false); //calls for a method returns the int value after hashing times as requested
        if (numOfHashesSecondFun != 0) { //checks if we need to use the other function
            int secondFuncUrlValue = hashItIn(numOfHashesSecondFun, url, stringSecondHashFun, true);
            return bitArray[FirstFuncUrlValue] == 1 && bitArray[secondFuncUrlValue] == 1;
    }
        return bitArray[FirstFuncUrlValue] == 1; //If there's no second hash function
    }
};