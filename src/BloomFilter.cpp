#include <string>
#include <vector>
class BloomFilter {
private:
int numOfHashesFirstFun;
int numOfHashesSecondFun;
std::vector<int> bitArray;
public:
// initializing the BloomFilter instance.
BloomFilter(int size, int numOfHashesFirstFun, int numOfHashesSecondFun) : bitArray(size),  numOfHashesFirstFun(numOfHashesFirstFun), numOfHashesSecondFun(numOfHashesSecondFun) {}
};