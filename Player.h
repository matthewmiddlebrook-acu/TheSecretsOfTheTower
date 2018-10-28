#pragma once

#include "person.h"
#include "location.h"

#include <iostream>
using namespace std;

class Player : public Person {
    private:
        Location* currentLocation;
        vector<Location*> visitedLocations;

        static Player* p_instance;
        Player();
    public:
        static Player* getPlayer();
        
        void move(Direction dir);
        void getItem(Item* pickup);
}