#include <string>
#include <vector>
#include "FalsePositiveCheck.h"
#include "BloomFilter.h"
#include "AddURLToBlacklist.h"

//@brief This function adds the url to the blacklist
void AddURLToBlacklist::execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) {
    bloomFilter->addItem(url);
    blacklistVec->addItemToSet(url);
}
