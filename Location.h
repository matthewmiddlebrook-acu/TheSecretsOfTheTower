#include "GameObject.h"
#include "Person.h"
#include "Item.h"

#include <iostream>
#include <vector>
using namespace std;

enum Direction{NORTH, SOUTH, EAST, WEST};

class Location : GameObject {
    private:
        Location* locations[4];
        vector<Item*> items;
        vector<Person*> people;
    public:
        Location(string name, string desc) : GameObject(name, desc) {};
        
        Location* getLocation(Direction dir);
        void setDirection(Direction dir, Location *loc);
        bool checkDirection(Direction dir);
        
        void addItem(Item* item);
        void removeItem(Item* item);
        
        void addPerson(Person* person);
        void removePerson(Person* person);
};