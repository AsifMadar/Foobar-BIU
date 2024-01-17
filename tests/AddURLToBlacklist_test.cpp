#include <gtest/gtest.h>
#include <vector>
#include "../src/BloomFilter.h"
#include "../src/AddURLToBlacklist.h"
#include "../src/FalsePositiveCheck.h"
using namespace std;


static vector<int> intVec = {1, 2};
static HashFuncs func(intVec);
static const vector<HashFuncs::FuncPointer> *functions12 = func.getFuncsVec();


TEST(AddURLToBlacklist, ValidAnswer1) {
    BloomFilter bloom(10, *functions12);
    AddURLToBlacklist addToBlackList = AddURLToBlacklist();
    FalsePositiveCheck falsePositive = FalsePositiveCheck();
    addToBlackList.execute(&bloom, &falsePositive, "HelloWorld");
    ASSERT_EQ(bloom.getItem("HelloWorld"), true);
    ASSERT_EQ(falsePositive.ItemIsIn("HelloWorld"), true);

}

TEST(AddURLToBlacklist, ValidAnswer2) {
    BloomFilter bloom(10, *functions12);
    AddURLToBlacklist addToBlackList = AddURLToBlacklist();
    FalsePositiveCheck falsePositive = FalsePositiveCheck();
    addToBlackList.execute(&bloom, &falsePositive, "akfa lfnalfbslkdhur29ry 19pja hdjskar1 3uqajsdakg3o8rgasd");
    ASSERT_EQ(bloom.getItem("akfa lfnalfbslkdhur29ry 19pja hdjskar1 3uqajsdakg3o8rgasd"), true);
    ASSERT_EQ(falsePositive.ItemIsIn("akfa lfnalfbslkdhur29ry 19pja hdjskar1 3uqajsdakg3o8rgasd"), true);

}
