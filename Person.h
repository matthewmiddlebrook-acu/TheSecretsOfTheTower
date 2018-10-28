#include "GameObject.h"
#include "Item.h"
#include "Inventory.h"

#include <iostream>
using namespace std;

class Person : GameObject {
    private:
        vector<string> dialogue;
        Inventory* inventory;
    public:
        string getDialogue(int index) { return dialogue.at(index); }
        void giveItem(Person* recipient, Item* gift);
};