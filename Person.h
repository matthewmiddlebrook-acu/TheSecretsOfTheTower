#ifndef PERSON_H
#define PERSON_H

#include "GameObject.h"
#include "Item.h"

#include <iostream>
#include <vector>
using namespace std;

class Person : public GameObject {
    private:
        vector<string> dialogue;
        vector<Item*> inventory;
    public:
        Person(string name = "", string desc = "") : GameObject(name, desc) {}
        string getDialogue() { return dialogue.at(rand() % dialogue.size()); }
        void setDialogue(string text) { dialogue.push_back(text); }
        void giveItem(Person* recipient, Item* gift);
        void addItem(Item* item) { inventory.push_back(item); }
        vector<Item*>* getItems() { return &inventory; }
        bool hasItem(string item_name);
};

#endif