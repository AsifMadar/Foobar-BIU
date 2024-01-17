#include <string>
#include <vector>
#include <set>
#include <functional>
#include "FalsePositiveCheck.h"
#include "BloomFilter.h"
#include "AddURLToBlacklist.h"


void AddURLToBlacklist::execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) {
    bloomFilter->addItem(url);
    blacklistVec->addItemToSet(url);
}
