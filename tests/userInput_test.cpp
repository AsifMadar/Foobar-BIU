#include <gtest/gtest.h>
#include "../src/userInput.cpp"

TEST(ReadLineNumbersTest, ValidInput) {
	std::istringstream dummyIStream("200 20\n8 1 2");
	std::vector<int>* vec = new std::vector<int>;
	readLineNumbers(dummyIStream, vec);

	ASSERT_EQ((*vec)[0], 200);
	ASSERT_EQ((*vec)[1], 20);

	vec->clear();
	readLineNumbers(dummyIStream, vec);

	ASSERT_EQ((*vec)[0], 8);
	ASSERT_EQ((*vec)[1], 1);
	ASSERT_EQ((*vec)[2], 2);
}

TEST(ReadLineNumbersTest, InvalidInput) {
	std::istringstream dummyIStream("10 a 5\n4 1\nhello\n 2 but why\n230 2 1");
	std::vector<int>* vec = new std::vector<int>;
	readLineNumbers(dummyIStream, vec);

	// Should read next line instead
	ASSERT_EQ((*vec)[0], 4);
	ASSERT_EQ((*vec)[1], 1);

	vec->clear();
	readLineNumbers(dummyIStream, vec);

	ASSERT_EQ((*vec)[0], 230);
	ASSERT_EQ((*vec)[1], 2);
	ASSERT_EQ((*vec)[2], 1);
}
