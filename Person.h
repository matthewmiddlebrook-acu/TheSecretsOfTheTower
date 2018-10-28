#pragma once

#include "GameObject.h"
#include "Item.h"
#include "Inventory.h"

#include <iostream>
#include <vector>
using namespace std;

class Person : public GameObject {
    private:
        vector<string> dialogue;
        Inventory* inventory;
    public:
        string getDialogue(int index) { return dialogue.at(index); }
        void giveItem(Person* recipient, Item* gift);
};