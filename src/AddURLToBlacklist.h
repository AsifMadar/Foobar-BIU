#pragma once
#include <string>
#include <vector>
#include "FalsePositiveCheck.h"
#include "BloomFilter.h"

class AddURLToBlacklist {

public:

    void execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url);
};