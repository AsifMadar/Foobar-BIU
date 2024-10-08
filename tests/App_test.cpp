#include <gtest/gtest.h>
#include <stdexcept>
#include <vector>
#include "../src/App.h"
#include "../src/FalsePositiveCheck.h"
#include "../src/IAction.h"
#include "../src/InStreamInput.h"

class TestAction: public IAction {
	public:
		virtual void execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) override {
			1;
		};
};

static TestAction testAction{};
static std::map<int, IAction*> actions = {{1, &testAction}, {2, &testAction}};

TEST(AppTest, Constructor) {
	std::istringstream dummyIStream("");
	InStreamInput userInput(dummyIStream);
	
	EXPECT_NO_THROW(App(&userInput, actions, 2));
}

TEST(AppTest, run) {
	// We can't test an infinite loop... unless it throws ;)
	std::istringstream dummyIStream("1 2\n1 www.example.com");
	InStreamInput userInput(dummyIStream);
	App app(&userInput, actions, 2);
	EXPECT_THROW(app.run(), std::runtime_error);

	std::istringstream dummyIStream2("2 1\n2 www.example.com\n2 1 \na 2");
	InStreamInput userInput2(dummyIStream2);
	App app2(&userInput2, actions, 2);
	EXPECT_THROW(app2.run(), std::runtime_error);
}

TEST(AppTest, runNextIteration) {
	std::istringstream dummyIStream("8 2\n1 www.example.com");
	InStreamInput userInput(dummyIStream);
	App app(&userInput, actions, 2);
	EXPECT_NO_THROW(app.runNextIteration()); // Load settings
	EXPECT_NO_THROW(app.runNextIteration()); // Execute action #1
	EXPECT_THROW(app.runNextIteration(), std::runtime_error); // Out of input

	std::istringstream dummyIStream2("8 1 2\n1 www.example.com\n2 www.example.com");
	InStreamInput userInput2(dummyIStream2);
	App app2(&userInput2, actions, 2);
	EXPECT_NO_THROW(app2.runNextIteration()); // Load settings
	EXPECT_NO_THROW(app2.runNextIteration()); // Execute action #1
	EXPECT_NO_THROW(app2.runNextIteration()); // Execute action #2
	EXPECT_THROW(app2.runNextIteration(), std::runtime_error);
}
