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

void Location::setDirection(Direction dir, Location* loc) {
    locations[dir] = loc;
}

bool Location::checkDirection(Direction dir) {
    return locations[dir] != NULL;
}

void Location::addItem(Item* item) {
    items.push_back(item);
}

Item* Location::removeItem(Item* item) {

}

void Location::addPerson(Person* person) {
    people.push_back(person);
}

Person* Location::removePerson(Person* person) {

}