#include <string>
class BloomFilter{
private:
int numOfHashesFirstFun;
int numOfHashesSecondFun;
int* bitArray;
public:
// initializing the BloomFilter instance.
BloomFilter(int size, int numOfHashesFirstFun, int numOfHashesSecondFun) {
    bitArray = new int[size];
    this->numOfHashesFirstFun = numOfHashesFirstFun;
    this->numOfHashesSecondFun = numOfHashesSecondFun;
}
//destructor
~BloomFilter(){
    delete[] bitArray;
}
void addItem(std::string url) {
    
}
};