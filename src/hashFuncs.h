#pragma once
#include <functional>
#include <string>

namespace hashFuncs {
	typedef std::size_t const (*FuncPointer)(std::string);

	extern const int functionsNum;
	extern hashFuncs::FuncPointer functions[2];
}
