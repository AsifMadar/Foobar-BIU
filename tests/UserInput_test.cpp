#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include "../src/UserInput.cpp"

TEST(ReadLineNumbersTest, ValidInput) {
	std::istringstream dummyIStream("200 20\n8 1 2");
	UserInput userInput(dummyIStream);
	std::vector<int> vec = {};

	userInput.readLineNumbers(&vec);
	ASSERT_EQ(vec[0], 200);
	ASSERT_EQ(vec[1], 20);

	userInput.readLineNumbers(&vec);
	ASSERT_EQ(vec[0], 8);
	ASSERT_EQ(vec[1], 1);
	ASSERT_EQ(vec[2], 2);
}

TEST(ReadLineNumbersTest, InvalidInput) {
	std::istringstream dummyIStream("10 a 5\n4 1\nhello\n 2 but why\n230 2 1");
	UserInput userInput(dummyIStream);
	std::vector<int> vec = {};

	userInput.readLineNumbers(&vec);
	ASSERT_EQ(vec[0], 4);
	ASSERT_EQ(vec[1], 1);

	userInput.readLineNumbers(&vec);
	ASSERT_EQ(vec[0], 230);
	ASSERT_EQ(vec[1], 2);
	ASSERT_EQ(vec[2], 1);
}

TEST(ReadLineNumbersTest, MinNumbers) {
	std::istringstream dummyIStream("1 2\n 5\n 4 3 5\n 41");
	UserInput userInput(dummyIStream);
	std::vector<int> vec = {};

	userInput.readLineNumbers(&vec, 2);
	ASSERT_EQ(vec[0], 1);
	ASSERT_EQ(vec[1], 2);

	userInput.readLineNumbers(&vec, 3);
	ASSERT_EQ(vec[0], 4);
	ASSERT_EQ(vec[1], 3);
	ASSERT_EQ(vec[2], 5);

	userInput.readLineNumbers(&vec);
	ASSERT_EQ(vec[0], 41);
}

TEST(ReadLineNumbersTest, MaxNumbers) {
	std::istringstream dummyIStream("1 2 3\n 5\n2\n 4 3 5\n 41 2");
	UserInput userInput(dummyIStream);
	std::vector<int> vec = {};

	userInput.readLineNumbers(&vec, 1, 2);
	ASSERT_EQ(vec[0], 5);

	userInput.readLineNumbers(&vec, 2, 3);
	ASSERT_EQ(vec[0], 4);
	ASSERT_EQ(vec[1], 3);
	ASSERT_EQ(vec[2], 5);

	ASSERT_EQ(userInput.readLineNumbers(&vec, 1, 1), -1);
}

TEST(ReadLineNumbersTest, ReturnValue) {
	std::istringstream dummyIStream("1 2\n 5\n 41");
	UserInput userInput(dummyIStream);
	std::vector<int> vec = {};

	ASSERT_EQ(userInput.readLineNumbers(&vec, 2), 0);
	ASSERT_EQ(userInput.readLineNumbers(&vec, 2), -1);
}

TEST(ReadLineNumbersTest, TrailingWhitespace) {
	std::istringstream dummyIStream("1 2 \n 5 \n2 a ");
	UserInput userInput(dummyIStream);
	std::vector<int> vec = {};

	userInput.readLineNumbers(&vec);
	ASSERT_EQ(vec[0], 1);
	ASSERT_EQ(vec[1], 2);
	ASSERT_EQ(vec.size(), 2);

	userInput.readLineNumbers(&vec);
	ASSERT_EQ(vec[0], 5);
	ASSERT_EQ(vec.size(), 1);

	userInput.readLineNumbers(&vec);
	ASSERT_EQ(vec.size(), 0);
}

TEST(GetFilterSettingsTest, ValidInput) {
	std::istringstream dummyIStream("200 2\n8 1 2");
	UserInput userInput(dummyIStream);
	std::vector<int> vec = {};

	userInput.getFilterSettings(&vec, 3);
	ASSERT_EQ(vec[0], 200);
	ASSERT_EQ(vec[1], 2);

	userInput.getFilterSettings(&vec, 3);
	ASSERT_EQ(vec[0], 8);
	ASSERT_EQ(vec[1], 1);
	ASSERT_EQ(vec[2], 2);
}

TEST(GetFilterSettingsTest, InvalidInput) {
	std::istringstream dummyIStream("10 a 5\n1 2 3\n4 2\n4 1\n\n4 1hello\n 2 but why\n230 2 3\n230 2 1");
	UserInput userInput(dummyIStream);
	std::vector<int> vec = {};

	userInput.getFilterSettings(&vec, 2);
	ASSERT_EQ(vec[0], 4);
	ASSERT_EQ(vec[1], 1);

	userInput.getFilterSettings(&vec, 3);
	ASSERT_EQ(vec[0], 230);
	ASSERT_EQ(vec[1], 2);
	ASSERT_EQ(vec[2], 1);
}

TEST(GetFilterSettingsTest, ReturnValue) {
	std::istringstream dummyIStream("1 1\n 5\n 41 2");
	UserInput userInput(dummyIStream);
	std::vector<int> vec = {};

	ASSERT_EQ(userInput.getFilterSettings(&vec, 2), 0);
	ASSERT_EQ(userInput.getFilterSettings(&vec, 2), -1);
}

TEST(GetFilterSettingsTest, TrailingWhitespace) {
	std::istringstream dummyIStream("1 1 \n 5 2 1 \n2 a ");
	UserInput userInput(dummyIStream);
	std::vector<int> vec = {};

	userInput.getFilterSettings(&vec, 2);
	ASSERT_EQ(vec[0], 1);
	ASSERT_EQ(vec[1], 1);
	ASSERT_EQ(vec.size(), 2);

	userInput.getFilterSettings(&vec, 3);
	ASSERT_EQ(vec[0], 5);
	ASSERT_EQ(vec[1], 2);
	ASSERT_EQ(vec[2], 1);
	ASSERT_EQ(vec.size(), 3);

	userInput.getFilterSettings(&vec, 2);
	ASSERT_EQ(vec.size(), 0);
}

TEST(GetUserActionAndURLTest, ValidInput) {
	std::istringstream dummyIStream("1 hi\n2 www.example.com\n2 https://www.example.com\n1 12");
	UserInput userInput(dummyIStream);
	int a;
	std::string str;

	userInput.getUserActionAndURL(&a, &str, 3);
	ASSERT_EQ(a, 1);
	ASSERT_EQ(str, "hi");

	userInput.getUserActionAndURL(&a, &str, 3);
	ASSERT_EQ(a, 2);
	ASSERT_EQ(str, "www.example.com");

	userInput.getUserActionAndURL(&a, &str, 3);
	ASSERT_EQ(a, 2);
	ASSERT_EQ(str, "https://www.example.com");

	userInput.getUserActionAndURL(&a, &str, 3);
	ASSERT_EQ(a, 1);
	ASSERT_EQ(str, "12");
}

TEST(GetUserActionAndURLTest, InvalidInput) {
	std::istringstream dummyIStream("11 \n 1 hi\n2 hi\n5 hi\n0 hi\n1 www.example.com\n2 https://www.example.com\n1  \n2 f");
	UserInput userInput(dummyIStream);
	int a;
	std::string str;

	userInput.getUserActionAndURL(&a, &str, 3);
	ASSERT_EQ(a, 1);
	ASSERT_EQ(str, "hi");

	userInput.getUserActionAndURL(&a, &str, 3);
	ASSERT_EQ(a, 2);
	ASSERT_EQ(str, "hi");

	userInput.getUserActionAndURL(&a, &str, 3);
	ASSERT_EQ(a, 1);
	ASSERT_EQ(str, "www.example.com");

	userInput.getUserActionAndURL(&a, &str, 3);
	ASSERT_EQ(a, 2);
	ASSERT_EQ(str, "https://www.example.com");

	userInput.getUserActionAndURL(&a, &str, 3);
	ASSERT_EQ(a, 2);
	ASSERT_EQ(str, "f");
}

TEST(GetUserActionAndURLTest, MaxNumber) {
	std::istringstream dummyIStream("51 www.example.com\n5 www.example.com\n2 https://www.example.com\n1  \n12 f");
	UserInput userInput(dummyIStream);
	int a;
	std::string str;

	userInput.getUserActionAndURL(&a, &str, 10);
	ASSERT_EQ(a, 5);
	ASSERT_EQ(str, "www.example.com");

	userInput.getUserActionAndURL(&a, &str, 13);
	ASSERT_EQ(a, 2);
	ASSERT_EQ(str, "https://www.example.com");

	userInput.getUserActionAndURL(&a, &str, 13);
	ASSERT_EQ(a, 12);
	ASSERT_EQ(str, "f");
}

TEST(GetUserActionAndURLTest, ReturnValue) {
	std::istringstream dummyIStream("1 www.example.com\n5\n a\n");
	UserInput userInput(dummyIStream);
	int a;
	std::string str;

	ASSERT_EQ(userInput.getUserActionAndURL(&a, &str, 3), 0);
	ASSERT_EQ(userInput.getUserActionAndURL(&a, &str, 3), -1);
}
