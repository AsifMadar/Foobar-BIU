#pragma once
#include <functional>
#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class HashFuncs {
	public:
		typedef std::size_t const (*FuncPointer)(std::string);

		HashFuncs(std::vector<int> const hashFuncsIds);
		~HashFuncs();
		HashFuncs(const HashFuncs& other);
		HashFuncs(HashFuncs&& other) noexcept;
		HashFuncs& operator=(const HashFuncs& other);
		HashFuncs& operator=(HashFuncs&& other);

		const std::vector<HashFuncs::FuncPointer>* getFuncsVec();
		static int getFuncsNum();

	private:
		std::vector<HashFuncs::FuncPointer>* funcs = new std::vector<HashFuncs::FuncPointer>;
};
