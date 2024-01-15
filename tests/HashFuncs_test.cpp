#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>
#include "../src/HashFuncs.cpp"

TEST(HashFuncsTest, Contructor) {
	std::vector<int> vec = {};
	EXPECT_NO_THROW(HashFuncs{vec});

	vec.push_back(1);
	EXPECT_NO_THROW(HashFuncs{vec});

	vec.push_back(HashFuncs::getFuncsNum());
	EXPECT_NO_THROW(HashFuncs{vec});

	vec.push_back(HashFuncs::getFuncsNum() + 1);
	EXPECT_THROW(HashFuncs{vec}, std::invalid_argument);

	vec.pop_back();
	vec.push_back(-1);
	EXPECT_THROW(HashFuncs{vec}, std::invalid_argument);
}

TEST(HashFuncsTest, getFuncsVec) {
	std::vector<int> vec = {1};
	HashFuncs hf = HashFuncs(vec);
	auto hfVec = hf.getFuncsVec();
	ASSERT_EQ(hfVec->size(), 1);

	vec.push_back(2);
	HashFuncs hf2 = HashFuncs(vec);
	auto hfVec2 = hf2.getFuncsVec();
	ASSERT_EQ(hfVec2->size(), 2);

	ASSERT_NO_THROW((*hfVec2)[0]("hi"));
}
