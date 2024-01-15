#include <string>
#include <vector>
#include <set>
#include <functional>

using namespace std;

class FalsePositive {
    
private:   
set<string> itemVec;

public:
    FalsePositive() {}
    set<string> getItemsSet() {
        return itemVec;
    }
    void addItemToSet(string item) {
        itemVec.insert(item);
    }

    set<string> getItemVec() {return itemVec;}
};