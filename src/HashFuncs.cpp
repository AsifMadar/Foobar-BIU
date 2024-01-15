#include <functional>
#include <stdexcept>
#include <string>
#include <vector>
#include "./HashFuncs.h"


/* In this exercise, we are required to implement 2 hash functions: the first one runs std::hash once,
	and the second one runs std::hash twice. These are the next two functions */
static std::size_t const hashFunction1(std::string str) {
	return std::hash<std::string>{}(str);
}

static std::size_t const hashFunction2(std::string str) {
	std::string interimVal = std::to_string(std::hash<std::string>{}(str));
	return std::hash<std::string>{}(interimVal);
}

const int functionsNum = 2;
const HashFuncs::FuncPointer functions[2] = { hashFunction1, hashFunction2 };

HashFuncs::HashFuncs(std::vector<int> const hashFuncsIds) {
	for (int id: hashFuncsIds) {
		if (functionsNum < id || id < 1) {
			throw std::invalid_argument("Provided id is not in range [1, HashFuncs::getFuncsNum()]");
		}
		this->funcs->push_back(functions[id]);
	}
};

HashFuncs::~HashFuncs() {
	// delete this->funcs;
};

const std::vector<HashFuncs::FuncPointer>* HashFuncs::getFuncsVec() {
	return this->funcs;
}

int HashFuncs::getFuncsNum() {
	return functionsNum;
}
