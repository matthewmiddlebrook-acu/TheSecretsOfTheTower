#include <iostream>
using namespace std;

enum Direction{NORTH, SOUTH, EAST, WEST};

class Location{
    public:
        Location* getLocation(Direction dir);
        void setDirection(Direction dir, Location* loc);
        bool checkDirection(Direction dir);

    private:
        Location* locations;
        Item* items;
        string description;
        Person* people;
};