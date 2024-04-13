#pragma once
#include <string>
#include <ostream>
#include "FalsePositiveCheck.h"
#include "BloomFilter.h"
#include "IAction.h"

class CheckURLInBlacklist : public IAction {
    public:
        CheckURLInBlacklist(std::ostream& outStream);

        void execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) override;
        std::string executeGetString(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url);

    private:
        std::ostream& outStream;
};
