#pragma
#include <string>
#include <vector>
#include <set>
#include <functional>

using namespace std;

class FalsePositive {
    
private:   
set<string> itemSet;

public:
    FalsePositive() {}
    set<string> getItemsSet();
    void addItemToSet(string item);
    bool ItemIsIn(string item);

    
};