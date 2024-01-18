#pragma once
#include <string>
#include <vector>
#include <set>

using namespace std;

class FalsePositiveCheck {
    
    private:   
        set<string> itemSet;

    public:
        FalsePositiveCheck() {}
        set<string> getItemsSet();
        void addItemToSet(string item);
        bool ItemIsIn(string item);
};