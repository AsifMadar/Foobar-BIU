#pragma once
#include <string>
#include <vector>
#include "FalsePositiveCheck.h"
#include "BloomFilter.h"
#include "IAction.h"

class AddURLToBlacklist : public IAction{

public:
    void execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) override;
};