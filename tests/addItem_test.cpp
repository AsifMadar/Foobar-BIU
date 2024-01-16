#include <gtest/gtest.h>
#include "../src/BloomFilter.cpp"
#include <vector>
#include "../src/hashFuncs.h"
using namespace std;

vector<hashFuncs::FuncPointer> Functions2 = {hashFuncs::functions[0], hashFuncs::functions[1]};

int isNotEmpty(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == 1) {
           return 1;
        }
    }
    return 0;
}

TEST(AddItem, checkIfNotEmpty1) {
    BloomFilter bloom(10, Functions2);
    bloom.addItem("helloWorld");
    ASSERT_EQ(isNotEmpty(bloom.getBitArray()), 1);
    }

TEST(AddItem, checkIfNotEmpty2) {
    BloomFilter bloom(150, Functions2);
    bloom.addItem("helloworld");
    ASSERT_EQ(isNotEmpty(bloom.getBitArray()), 1);
    }

TEST(AddItem, checkIfNotEmpty3) {
    BloomFilter bloom(10, Functions2);
    bloom.addItem("hello World");
    ASSERT_EQ(isNotEmpty(bloom.getBitArray()), 1);
    }