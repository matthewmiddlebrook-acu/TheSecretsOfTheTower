#ifndef PLAYER_H
#define PLAYER_H

#include "Person.h"
#include "Location.h"

#include <set>
#include <iostream>
using namespace std;

class Player : public Person {
    private:
        Location* currentLocation;
        set<Location*> visitedLocations;

        static Player* p_instance;
        Player(string name = "", string desc = "") : Person(name, desc) {}
    public:
        static Player* getPlayer();
        
        bool move(Direction dir);
        
        //void addItem(Item* pickup);
        void useItem();

        Location* getLocation();
        void setLocation(Location *location);
};

#endif