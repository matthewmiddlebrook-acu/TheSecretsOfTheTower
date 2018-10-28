#include "Item.h"

#include <iostream>
using namespace std;

class Inventory {
    public:
        void addItem(Item* item);
        Item remove item();
        
    private:
        Item **inventory;
};