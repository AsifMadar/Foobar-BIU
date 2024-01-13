#include <gtest/gtest.h>
#include "../src/BloomFilter.cpp"
#include <vector>

using namespace std;
int isNotEmpty(vector<int> vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == 1) {
           return 1;
        }
    }
    return 0;
}

TEST(ConstructorTest, ValidValues) {
    BloomFilter bloom(10, 1, 1);
    ASSERT_EQ(bloom.getBitArray().size(), 10);
    ASSERT_EQ(bloom.getNumOfHashesFirstFun(), 1);
    ASSERT_EQ(bloom.getNumOfHashesSecondFun(), 1);
}

TEST(ConstructorTest, InvalidValues) {
    BloomFilter bloom(10, 1, 1);
    ASSERT_NE(bloom.getBitArray().size(), 30);
    ASSERT_NE(bloom.getNumOfHashesFirstFun(), 4);
    ASSERT_NE(bloom.getNumOfHashesSecondFun(), 2);
}

TEST(ConstructorTest, CopyBitArray) {
        BloomFilter bloom(10, 1, 1);
        vector<int> copyBitArray = bloom.getBitArray();
        copyBitArray[0] = 5;
        ASSERT_EQ(bloom.getBitArray()[0], 0);
}

TEST(AddItem, checkIfNotEmpty1) {
    BloomFilter bloom(10, 1, 1);
    bloom.addItem("helloWorld");
    ASSERT_EQ(isNotEmpty(bloom.getBitArray()), 1);
    }

TEST(AddItem, checkIfNotEmpty2) {
    BloomFilter bloom(150, 2, 10);
    bloom.addItem("helloworld");
    ASSERT_EQ(isNotEmpty(bloom.getBitArray()), 1);
    }

TEST(AddItem, checkIfNotEmpty3) {
    BloomFilter bloom(10, 30, 300);
    bloom.addItem("hello World");
    ASSERT_EQ(isNotEmpty(bloom.getBitArray()), 1);
    }