#pragma once
#include <string>
#include <vector>
#include "FalsePositiveCheck.h"
#include "BloomFilter.h"

class CheckURLInBlacklist {

public:

    void execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url);
    std::string executeGetString(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url);

};