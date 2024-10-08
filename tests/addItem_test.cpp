#include <gtest/gtest.h>
#include <vector>
#include "../src/BloomFilter.h"
#include "../src/HashFuncs.h"

using namespace std;

static vector<int> intVec = {1, 2};
static HashFuncs func(intVec);
static const vector<HashFuncs::FuncPointer> *functions12 = func.getFuncsVec();

int isNotEmpty(vector<bool> vec) {
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i] == 1) {
            return true;
        }
    }
    return false;
}

TEST(AddItem, checkIfNotEmpty1) {
    BloomFilter bloom(10, *functions12);
    bloom.addItem("helloWorld");
    ASSERT_EQ(isNotEmpty(bloom.getBitArray()), true);
}

TEST(AddItem, checkIfNotEmpty2) {
    BloomFilter bloom(150, *functions12);
    bloom.addItem("helloworld");
    ASSERT_EQ(isNotEmpty(bloom.getBitArray()), true);
}

TEST(AddItem, checkIfNotEmpty3) {
    BloomFilter bloom(10, *functions12);
    bloom.addItem("hello World");
    ASSERT_EQ(isNotEmpty(bloom.getBitArray()), true);
}
