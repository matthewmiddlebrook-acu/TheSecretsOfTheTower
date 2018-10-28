#include "GameObject.h"
#include "Item.h"
#include "Person.h"

#include <iostream>
using namespace std;

enum Direction{NORTH, SOUTH, EAST, WEST};

class Location : GameObject {
    public:
        Location* getLocation(Direction dir);
        void setDirection(Direction dir, Location* loc);
        bool checkDirection(Direction dir);

    private:
        Location** locations;
        Item** items;
        Person** people;
};