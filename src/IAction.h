#pragma once
#include <string>
#include <vector>
#include "./BloomFilter.h"

class IAction {
	public:
		virtual void execute(BloomFilter* bloomFilter, std::vector<std::string>* blacklistVec, std::string url) = 0;
};
