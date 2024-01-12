#include <gtest/gtest.h>
#include "../src/BloomFilter.cpp"
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

