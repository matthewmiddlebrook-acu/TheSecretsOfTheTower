#ifndef LOCATION_H
#define LOCATION_H

#include "GameObject.h"
#include "Person.h"
#include "Item.h"

#include <iostream>
#include <vector>
using namespace std;

// If you want to add more directions to the Direction enum, 
// keep NUM_DIRECTIONS at the end for correct total length
enum Direction{NORTH, SOUTH, EAST, WEST, UP, DOWN, NUM_DIRECTIONS};

class Location : public GameObject {
    private:
        Location* locations[NUM_DIRECTIONS];
        vector<Item*> items;
        vector<Person*> people;
    public:
        Location(string name = "", string desc = "");

        Location* getLocation(Direction dir);
        //reEntry means it automatically connects the other location to this one 
        void setDirection(Direction dir, Location* loc, bool reEntry);
        bool checkDirection(Direction dir);

        Direction oppositeDirection(Direction d);

        void addItem(Item* item);
        Item* removeItem(Item* item);

        void addPerson(Person* person);
        Person* removePerson(Person* person);

        //Location* createLocations();
};

#endif