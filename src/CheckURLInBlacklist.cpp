#include <ostream>
#include <string>
#include "./BloomFilter.h"
#include "./CheckURLInBlacklist.h"
#include "./FalsePositiveCheck.h"

/// @param outStream The stream to write output into
CheckURLInBlacklist::CheckURLInBlacklist(std::ostream& outStream): outStream(outStream) {};

//@brief Prints true true if the given url is inside the blacklist, true false if its inside the bitArray but not in the blacklist and false if its not in the bitArray
//@param bloomFilter The object which contains the bitArray service
//@param blacklistVec The object which contains the check if the url is truly inside the blacklist
//@param url is the string which we check if it's inside the blacklist
void CheckURLInBlacklist::execute(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) {
    this->outStream << executeGetString(bloomFilter, blacklistVec, url) << std::endl;
}

//@brief Does the same like void CheckURLInBlackList just returns the string instead printing
//@return true true if the given url is inside the blacklist, true false if its inside the bitArray but not in the blacklist and false if its not in the bitArray
string CheckURLInBlacklist::executeGetString(BloomFilter* bloomFilter, FalsePositiveCheck* blacklistVec, std::string url) {
   if(!bloomFilter->getItem(url)) {
       return "false";
   }
   if(blacklistVec ->ItemIsIn(url)) {
       return "true true";
   }
      return "true false";
}

