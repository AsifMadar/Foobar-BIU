#include <gtest/gtest.h>
#include "../src/HashFuncConfirm.cpp"
#include <string>
#include <vector>

using namespace std;

TEST(addItemHashFunctionConfirm, addingItem) {
    FalsePositive hey;
    hey.addItemToSet("Hello world");
    string i = *hey.getItemsSet().find("Hello world");
    ASSERT_EQ(i, "Hello world");
    }