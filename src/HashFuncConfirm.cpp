#include <string>
#include <vector>
#include <set>
#include <functional>
#include "HashFuncConfirm.h"

using namespace std;
 
    set<string> FalsePositive::getItemsSet() {
        return itemSet;
    }
    void FalsePositive::addItemToSet(string item) {
        itemSet.insert(item);
    }

    bool FalsePositive::ItemIsIn(string item) {
        return itemSet.find(item) != itemSet.end();
    }