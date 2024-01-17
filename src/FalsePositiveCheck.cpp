#include <string>
#include <vector>
#include <set>
#include <functional>
#include "FalsePositiveCheck.h"

using namespace std;
 
    set<string> FalsePositiveCheck::getItemsSet() {
        return itemSet;
    }
    void FalsePositiveCheck::addItemToSet(string item) {
        itemSet.insert(item);
    }

    bool FalsePositiveCheck::ItemIsIn(string item) {
        return itemSet.find(item) != itemSet.end();
    }