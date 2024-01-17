#include <gtest/gtest.h>
#include <vector>
#include "../src/BloomFilter.h"
#include "../src/AddURLToBlacklist.h"
#include "../src/FalsePositiveCheck.h"
#include "../src/CheckURLInBlacklist.h"

using namespace std;


static vector<int> intVec = {1, 2};
static HashFuncs func(intVec);
static const vector<HashFuncs::FuncPointer> *functions12 = func.getFuncsVec();


TEST(CheckURLInBlacklist, ValidAnswer) {
    BloomFilter bloom(20000, *functions12);
    
    AddURLToBlacklist addToBlackList = AddURLToBlacklist();
    FalsePositiveCheck falsePositive = FalsePositiveCheck();
    CheckURLInBlacklist checkURLInBlacklist{};
    addToBlackList.execute(&bloom, &falsePositive, "HelloWorld");
    addToBlackList.execute(&bloom, &falsePositive, "-1");
    ASSERT_EQ(checkURLInBlacklist.executeGetString(&bloom, &falsePositive, "HelloWorld"), "true true");
    ASSERT_EQ(checkURLInBlacklist.executeGetString(&bloom, &falsePositive, "asldhjalasdhk"), "false");
    ASSERT_EQ(checkURLInBlacklist.executeGetString(&bloom, &falsePositive, ""), "false");
    ASSERT_EQ(checkURLInBlacklist.executeGetString(&bloom, &falsePositive, "-1"), "true true");
}

TEST(CheckURLInBlacklist, falsePositive) {
    BloomFilter bloom(20000, *functions12);
    bloom.addItem("HelloWorld");
    bloom.addItem("");
    AddURLToBlacklist addToBlackList = AddURLToBlacklist();
    FalsePositiveCheck falsePositive = FalsePositiveCheck();
    CheckURLInBlacklist checkURLInBlacklist{};
    ASSERT_EQ(checkURLInBlacklist.executeGetString(&bloom, &falsePositive, "HelloWorld"), "true false");
    ASSERT_EQ(checkURLInBlacklist.executeGetString(&bloom, &falsePositive, ""), "true false");


}

