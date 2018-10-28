#include "GameObject.h"
#include "Item.h"
#include "Inventory.h"

#include <iostream>
using namespace std;

class Person : GameObject {
    public:
        string getDialogue(int index) { return dialogue[index]; }
        void giveItem(Person* recipient, Item* gift);

    private:
        string** dialogue;
        Inventory* inventory;
};