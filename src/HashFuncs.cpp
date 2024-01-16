#include <functional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>
#include "./HashFuncs.h"


/* In this exercise, we are required to implement 2 hash functions: the first one runs std::hash once,
	and the second one runs std::hash twice. These are the next two functions */
/// @brief Hashes the input by calling `std::hash` once
static std::size_t const hashFunction1(std::string str) {
	return std::hash<std::string>{}(str);
}

/// @brief Hashes the input by calling `std::hash` twice
static std::size_t const hashFunction2(std::string str) {
	std::string interimVal = std::to_string(std::hash<std::string>{}(str));
	return std::hash<std::string>{}(interimVal);
}

static const int functionsNum = 2;
static const HashFuncs::FuncPointer functions[2] = { hashFunction1, hashFunction2 };

/// @param hashFuncsIds A vector of integers, each specifying the id of a hash function, in the range [1, HashFuncs::getFuncsNum()]
HashFuncs::HashFuncs(std::vector<int> const hashFuncsIds) {
	for (int id: hashFuncsIds) {
		if (functionsNum < id || id < 1) { // Validate arguments
			throw std::invalid_argument("Provided id is not in range [1, HashFuncs::getFuncsNum()]");
		}
		this->funcs->push_back(functions[id - 1]); // Add corresponding function to instance
	}
};

HashFuncs::~HashFuncs() {
	delete this->funcs;
};
HashFuncs::HashFuncs(const HashFuncs& other): funcs(other.funcs) {}
HashFuncs::HashFuncs(HashFuncs&& other) noexcept: funcs(std::exchange(other.funcs, nullptr)) {}
HashFuncs& HashFuncs::operator=(const HashFuncs& other) {
	*this = HashFuncs(other);
	return *this;
}
HashFuncs& HashFuncs::operator=(HashFuncs&& other) {
	std::swap(this->funcs, other.funcs);
	return *this;
}


/// @return A vector of the hash functions included with this instance
const std::vector<HashFuncs::FuncPointer>* HashFuncs::getFuncsVec() {
	return this->funcs;
}

/// @return The total number of hash functions available in this class
int HashFuncs::getFuncsNum() {
	return functionsNum;
}
