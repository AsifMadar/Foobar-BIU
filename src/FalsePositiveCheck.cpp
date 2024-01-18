#include <string>
#include <vector>
#include <set>
#include "FalsePositiveCheck.h"

using namespace std;
    
    //@return The item Set
    set<string> FalsePositiveCheck::getItemsSet() {
        return itemSet;
    }

    //@brief Adds the item to the set
    //@param item The item which added to the set
    void FalsePositiveCheck::addItemToSet(string item) {
        itemSet.insert(item);
    }
    
    //@brief Checks if the item is in the set
    //@param The item which checked if its inside the set
    //@return true if in otherwise false
    bool FalsePositiveCheck::ItemIsIn(string item) {
        return itemSet.find(item) != itemSet.end();
    }