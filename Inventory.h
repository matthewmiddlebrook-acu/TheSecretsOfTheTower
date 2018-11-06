/*#ifndef INVENTORY_H
#define INVENTORY_H

#include "Item.h"

#include <iostream>
#include <vector>
using namespace std;

class Inventory {
    private:
        vector<Item*> inventory;
    public:
        void addItem(Item* item) { std::cout << "INVENTORY\n\n"; inventory.push_back(item); };
        Item* remove(Item* item);
};

#endif */