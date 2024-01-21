#pragma once
#include <string>
#include "FalsePositiveCheck.h"
#include "BloomFilter.h"
#include "IAction.h"

class CheckURLInBlacklist : public IAction {

    public:
        void execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) override;
        std::string executeGetString(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url);
};