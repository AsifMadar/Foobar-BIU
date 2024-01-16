cmake_minimum_required(VERSION 3.14)
project("Foobar-BIU")

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
	googletest
	URL
	https://github.com/google/googletest/archive/03597a01ee50ed
	33e9dfd640b249b4be3799d395.zip
)

enable_testing()

set(MAIN_FILE src/main.cpp)
set(SOURCE_FILES
	src/App.cpp
	src/BloomFilter.cpp
	src/HashFuncs.cpp
	src/UserInput.cpp
)
set(TEST_FILES
	tests/addItem_test.cpp
	tests/App_test.cpp
	tests/getItem_test.cpp
	tests/HashFuncs_test.cpp
	tests/test_main.cpp
	tests/UserInput_test.cpp
)

add_executable(Foobar ${SOURCE_FILES} ${MAIN_FILE})
add_executable(FoobarDebugBuild ${SOURCE_FILES} ${MAIN_FILE})
add_executable(FoobarTests ${SOURCE_FILES} ${TEST_FILES})

target_compile_options(FoobarDebugBuild PRIVATE "-g" "-O0")

# Link Google Test to the test executable
target_link_libraries(FoobarTests PRIVATE gtest gtest_main)

# Include the source directory for tests
target_include_directories(FoobarTests PRIVATE src)

include(GoogleTest)
add_test(NAME FoobarTests COMMAND FoobarTests)
