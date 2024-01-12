#include <gtest/gtest.h>
#include "../src/BloomFilter.cpp"
#include <vector>
using namespace std;
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
TEST(AddItem, check) {
    BloomFilter bloom(10, 1, 1);
    bloom.addItem("helloWorld");

}