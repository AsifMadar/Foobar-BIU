#include <functional>
#include <string>

/* In this exercise, we are required to implement 2 hash functions: the first one runs std::hash once,
	and the second one runs std::hash twice. These are the next two functions */
std::size_t const hashFunction1(std::string str) {
	return std::hash<std::string>{}(str);
}

std::size_t const hashFunction2(std::string str) {
	std::string interimVal = std::to_string(std::hash<std::string>{}(str));
	return std::hash<std::string>{}(interimVal);
}

namespace hashFuncs {
	typedef std::size_t const (*FuncPointer)(std::string);

	extern const int functionsNum = 2;
	extern hashFuncs::FuncPointer functions[2] = { hashFunction1, hashFunction2 };
}
