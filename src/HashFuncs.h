#pragma once
#include <functional>
#include <stdexcept>
#include <string>
#include <vector>

class HashFuncs {
	public:
		typedef std::size_t const (*FuncPointer)(std::string);

		HashFuncs(std::vector<int> const hashFuncsIds);
		~HashFuncs();
		const std::vector<HashFuncs::FuncPointer>* getFuncsVec();
		static int getFuncsNum();

	private:
		std::vector<HashFuncs::FuncPointer>* funcs = new std::vector<HashFuncs::FuncPointer>;
};
