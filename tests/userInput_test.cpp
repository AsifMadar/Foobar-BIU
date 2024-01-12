#include <gtest/gtest.h>
#include "../src/userInput.cpp"

TEST(ReadLineNumbersTest, ValidInput) {
	std::istringstream dummyIStream("200 20\n8 1 2");
	std::vector<int>* vec = new std::vector<int>;

	readLineNumbers(dummyIStream, vec);
	ASSERT_EQ((*vec)[0], 200);
	ASSERT_EQ((*vec)[1], 20);

	readLineNumbers(dummyIStream, vec);
	ASSERT_EQ((*vec)[0], 8);
	ASSERT_EQ((*vec)[1], 1);
	ASSERT_EQ((*vec)[2], 2);
}

TEST(ReadLineNumbersTest, InvalidInput) {
	std::istringstream dummyIStream("10 a 5\n4 1\nhello\n 2 but why\n230 2 1");
	std::vector<int>* vec = new std::vector<int>;

	readLineNumbers(dummyIStream, vec);
	ASSERT_EQ((*vec)[0], 4);
	ASSERT_EQ((*vec)[1], 1);

	readLineNumbers(dummyIStream, vec);
	ASSERT_EQ((*vec)[0], 230);
	ASSERT_EQ((*vec)[1], 2);
	ASSERT_EQ((*vec)[2], 1);
}

TEST(ReadLineNumbersTest, MinNumbers) {
	std::istringstream dummyIStream("1 2\n 5\n 4 3 5\n 41");
	std::vector<int>* vec = new std::vector<int>;

	readLineNumbers(dummyIStream, vec, 2);
	ASSERT_EQ((*vec)[0], 1);
	ASSERT_EQ((*vec)[1], 2);

	readLineNumbers(dummyIStream, vec, 3);
	ASSERT_EQ((*vec)[0], 4);
	ASSERT_EQ((*vec)[1], 3);
	ASSERT_EQ((*vec)[2], 5);

	readLineNumbers(dummyIStream, vec);
	ASSERT_EQ((*vec)[0], 41);
}

TEST(ReadLineNumbersTest, MaxNumbers) {
	std::istringstream dummyIStream("1 2 3\n 5\n2\n 4 3 5\n 41 2");
	std::vector<int>* vec = new std::vector<int>;

	readLineNumbers(dummyIStream, vec, 1, 2);
	ASSERT_EQ((*vec)[0], 5);

	readLineNumbers(dummyIStream, vec, 2, 3);
	ASSERT_EQ((*vec)[0], 4);
	ASSERT_EQ((*vec)[1], 3);
	ASSERT_EQ((*vec)[2], 5);

	ASSERT_EQ(readLineNumbers(dummyIStream, vec, 1, 1), -1);
}

TEST(ReadLineNumbersTest, ReturnValue) {
	std::istringstream dummyIStream("1 2\n 5\n 41");
	std::vector<int>* vec = new std::vector<int>;

	ASSERT_EQ(readLineNumbers(dummyIStream, vec, 2), 0);
	ASSERT_EQ(readLineNumbers(dummyIStream, vec, 2), -1);
}
