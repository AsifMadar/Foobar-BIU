#pragma once
#include <string>
#include <vector>
#include "./BloomFilter.h"
#include "FalsePositiveCheck.h"

class IAction {
	public:
		virtual void execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) = 0;
};
