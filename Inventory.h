#include "Item.h"

#include <iostream>
using namespace std;

class Inventory {
    private:
        vector<Item*> inventory;
    public:
        void addItem(Item* item);
        Item* remove(Item* item);
};