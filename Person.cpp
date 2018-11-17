#include "Person.h"

#include <iostream>
using namespace std;

bool Person::hasItem(string item_name) {
    for (vector<Item*>::iterator it = inventory.begin() ; it != inventory.end(); ++it) {
        if ((*it)->getName() == item_name)
            return true;
    }
    return false;
}