#pragma once

#include "Item.h"

#include <iostream>
#include <vector>
using namespace std;

class Inventory {
    private:
        vector<Item*> inventory;
    public:
        void addItem(Item* item);
        Item* remove(Item* item);
};