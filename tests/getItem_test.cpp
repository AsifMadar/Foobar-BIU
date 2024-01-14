#include <gtest/gtest.h>
#include "../src/BloomFilter.cpp"
#include <vector>
#include "../src/hashFuncs.cpp"

using namespace std;

std::vector<hashFuncs::FuncPointer> hashFunctions1 = {hashFuncs::functions[0]};
std::vector<hashFuncs::FuncPointer> hashFunctions2 = {hashFuncs::functions[1]};
std::vector<hashFuncs::FuncPointer> hashFunctions12 = {hashFuncs::functions[0], hashFuncs::functions[1]};

int countInside(vector<int> vec) {
    int counter = 0;
    for(int i = 0; i < vec.size(); i++) {
        if(vec[i] == 1) {
           counter++;
        }
    }
    return counter;
}

TEST(GetItemTest, ValidAnswer1) {
    BloomFilter bloom(10, hashFunctions12);
    bloom.addItem("helloWorld");
    ASSERT_EQ(bloom.getItem("helloWorld"), true);
}

 TEST(GetItemTest, ValidAnswer2) {
    BloomFilter bloom(10, hashFunctions12);
    bloom.addItem("hello World");
    int flag = 0;
    if (bloom.getItem("hello World") == 1) {
        flag = 1;
    }
    ASSERT_EQ(flag, 1);
    }

TEST(GetItemTest, ValidAnswer3) {
    BloomFilter bloom(10, hashFunctions12);
    bloom.addItem("helloWorld");
    int flag = 0;
    if (bloom.getItem("helloWorld") == 1) {
        flag = 1;
    }
    ASSERT_EQ(flag, 1);
    }

TEST(GetItemTest, ValidAnswer4) {
    BloomFilter bloom(5000, hashFunctions12);
    bloom.addItem("helloWorld");
    int flag = 0;
    if (bloom.getItem("helloWorld") == 1) {
        flag = 1;
    }
    ASSERT_EQ(flag, 1);
    }

TEST(GetItemTest, checkingTwoPlacesInTheArray1) {
    BloomFilter bloom(10, hashFunctions12);
    bloom.addItem("helloWorld");
    ASSERT_EQ(countInside(bloom.getBitArray()), 2);
    }

    TEST(GetItemTest, checkingTwoPlacesInTheArray2) {
    BloomFilter bloom(9000, hashFunctions12);
    bloom.addItem("helloWorld");
    ASSERT_EQ(countInside(bloom.getBitArray()), 2);
    }

    TEST(GetItemTest, checkingTwoPlacesInTheArray3) {
    BloomFilter bloom(100, hashFunctions12);
    bloom.addItem("helloWorld");
    ASSERT_EQ(countInside(bloom.getBitArray()), 2);
    }

    TEST(GetItemTest, checkingTwoPlacesInTheArray4) {
    BloomFilter bloom(100, hashFunctions12);
    bloom.addItem("helloWorld31231231./sadwqexzcxc");
    ASSERT_EQ(countInside(bloom.getBitArray()), 2);
    }

    TEST(GetItemTest, checkingTwoPlacesInTheArray5) {
    BloomFilter bloom(100, hashFunctions12);
    bloom.addItem("Shalom vegam braha my name is nadir noder hanedarim mispar 1 baaretz/olam");
    ASSERT_EQ(countInside(bloom.getBitArray()), 2);
    }