#include <gtest/gtest.h>
#include "../src/BloomFilter.cpp"
#include <vector>

using namespace std;

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
    BloomFilter bloom(10, 1, 1);
    bloom.addItem("helloWorld");
    int flag = 0;
    if (bloom.getItem("helloWorld") == 1) {
        flag = 1;
    }
    ASSERT_EQ(flag, 1);
    }

 TEST(GetItemTest, ValidAnswer2) {
    BloomFilter bloom(10, 10, 1);
    bloom.addItem("hello World");
    int flag = 0;
    if (bloom.getItem("hello World") == 1) {
        flag = 1;
    }
    ASSERT_EQ(flag, 1);
    }

TEST(GetItemTest, ValidAnswer3) {
    BloomFilter bloom(10, 2, 10);
    bloom.addItem("helloWorld");
    int flag = 0;
    if (bloom.getItem("helloWorld") == 1) {
        flag = 1;
    }
    ASSERT_EQ(flag, 1);
    }

TEST(GetItemTest, ValidAnswer4) {
    BloomFilter bloom(5000, 2, 6);
    bloom.addItem("helloWorld");
    int flag = 0;
    if (bloom.getItem("helloWorld") == 1) {
        flag = 1;
    }
    ASSERT_EQ(flag, 1);
    }

TEST(GetItemTest, checkingTwoPlacesInTheArray1) {
    BloomFilter bloom(10, 1, 1);
    bloom.addItem("helloWorld");
    ASSERT_EQ(countInside(bloom.getBitArray()), 2);
    }

    TEST(GetItemTest, checkingTwoPlacesInTheArray2) {
    BloomFilter bloom(9000, 1, 1);
    bloom.addItem("helloWorld");
    ASSERT_EQ(countInside(bloom.getBitArray()), 2);
    }

    TEST(GetItemTest, checkingTwoPlacesInTheArray3) {
    BloomFilter bloom(100, 2, 17);
    bloom.addItem("helloWorld");
    ASSERT_EQ(countInside(bloom.getBitArray()), 2);
    }

    TEST(GetItemTest, checkingTwoPlacesInTheArray4) {
    BloomFilter bloom(100, 2, 2);
    bloom.addItem("helloWorld31231231./sadwqexzcxc");
    ASSERT_EQ(countInside(bloom.getBitArray()), 2);
    }

    TEST(GetItemTest, checkingTwoPlacesInTheArray5) {
    BloomFilter bloom(100, 2, 2);
    bloom.addItem("Shalom vegam braha my name is nadir noder hanedarim mispar 1 baaretz/olam");
    ASSERT_EQ(countInside(bloom.getBitArray()), 2);
    }