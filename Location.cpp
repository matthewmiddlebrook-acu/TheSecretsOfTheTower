#include "Location.h"

#include <iostream>
using namespace std;

Location::Location(string name, string desc) : GameObject(name, desc) {
    for (int i = 0; i < NUM_DIRECTIONS; i++) {
        locations[i] = NULL;
    }
}

Location* Location::getLocation(Direction dir) {
    return locations[dir];
}

void Location::setDirection(Direction dir, Location* loc, bool reEntry = true) {
    locations[dir] = loc;
    if (reEntry)
        loc->locations[oppositeDirection(dir)] = this;
}

bool Location::checkDirection(Direction dir) {
    return locations[dir] != NULL;
}

Direction Location::oppositeDirection(Direction d) {
    switch (d) {
        case NORTH:
            return SOUTH;
        case SOUTH:
            return NORTH;
        case EAST:
            return WEST;
        case WEST:
            return EAST;
    }
    return NUM_DIRECTIONS; // IDK what else to return
}

void Location::addItem(Item* item) {
    items.push_back(item);
}

Item* Location::removeItem(Item* item) {
	return NULL;
}

void Location::addPerson(Person* person) {
    people.push_back(person);
}

Person* Location::removePerson(Person* person) {
	return NULL;
}