#include <gtest/gtest.h>
#include <vector>
#include "../src/BloomFilter.h"
#include "../src/HashFuncs.h"

using namespace std;

static vector<int> intVec = {1, 2};
static HashFuncs func(intVec);
static const vector<HashFuncs::FuncPointer> *functions12 = func.getFuncsVec();

bool countInside(vector<bool> vec) {
    int counter = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 1) {
            counter++;
        }
    }
    return counter==2;
}

TEST(GetItemTest, ValidAnswer1) {
    BloomFilter bloom(10, *functions12);
    bloom.addItem("helloWorld");
    ASSERT_EQ(bloom.getItem("helloWorld"), true);
}

TEST(GetItemTest, ValidAnswer2) {
    BloomFilter bloom(10, *functions12);
    bloom.addItem("hello World");
    int flag = 0;
    if (bloom.getItem("hello World") == 1) {
        flag = 1;
    }
    ASSERT_EQ(flag, 1);
}

TEST(GetItemTest, ValidAnswer3) {
    BloomFilter bloom(10, *functions12);
    bloom.addItem("helloWorld");
    int flag = 0;
    if (bloom.getItem("helloWorld") == true) {
        flag = 1;
    }
    ASSERT_EQ(flag, 1);
}

TEST(GetItemTest, ValidAnswer4) {
    BloomFilter bloom(5000, *functions12);
    bloom.addItem("helloWorld");
    int flag = 0;
    if (bloom.getItem("helloWorld") == true) {
        flag = 1;
    }
    ASSERT_EQ(flag, 1);
}

TEST(GetItemTest, checkingTwoPlacesInTheArray1) {
    BloomFilter bloom(10, *functions12);
    bloom.addItem("helloWorld");
    ASSERT_EQ(countInside(bloom.getBitArray()), true);
}

TEST(GetItemTest, checkingTwoPlacesInTheArray2) {
    BloomFilter bloom(9000, *functions12);
    bloom.addItem("helloWorld");
    ASSERT_EQ(countInside(bloom.getBitArray()), true);
}

TEST(GetItemTest, checkingTwoPlacesInTheArray3) {
    BloomFilter bloom(100, *functions12);
    bloom.addItem("helloWorld");
    ASSERT_EQ(countInside(bloom.getBitArray()), true);
}

TEST(GetItemTest, checkingTwoPlacesInTheArray4) {
    BloomFilter bloom(100, *functions12);
    bloom.addItem("helloWorld31231231./sadwqexzcxc");
    ASSERT_EQ(countInside(bloom.getBitArray()), true);
}

TEST(GetItemTest, checkingTwoPlacesInTheArray5) {
    BloomFilter bloom(100, *functions12);
    bloom.addItem("Shalom vegam braha my name is nadir noder hanedarim mispar 1 baaretz/olam");
    ASSERT_EQ(countInside(bloom.getBitArray()), true);
}
