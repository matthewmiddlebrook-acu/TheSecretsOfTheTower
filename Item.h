#ifndef ITEM_H
#define ITEM_H

#include "GameObject.h"

#include <iostream>
using namespace std;

class Item : public GameObject {
    private:

    public:
        Item(string name = "", string desc = "") : GameObject(name, desc) {};
};

#endif