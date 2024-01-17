#include <string>
#include <vector>
#include "FalsePositiveCheck.h"
#include "BloomFilter.h"
#include "CheckURLInBlacklist.h"
#include <iostream>

using namespace std;

void CheckURLInBlacklist::execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) {
    cout << executeGetString(bloomFilter, blacklistVec, url) << endl;
}
string CheckURLInBlacklist::executeGetString(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) {
   if(!bloomFilter->getItem(url)) {
       return "false";
   }
   if(blacklistVec ->ItemIsIn(url)) {
    return "true true";
   }
   return "true false";
}

