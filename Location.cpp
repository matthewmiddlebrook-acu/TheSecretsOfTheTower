#include "Location.h"

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

Location::Location(string name, string desc) : GameObject(name) {
    setDescription(desc);

    for (int i = 0; i < NUM_DIRECTIONS; i++)
    {
        locations[i] = NULL;
    }
}

string Location::getDescription() {
    return descriptions.at("default");
}

void Location::setDescription(string desc) {
    descriptions.insert(pair<string, string>("default", desc));
}

// Gets the description if there is a special state (first entry or requires item), rather than just normal room description
string Location::getDescription(string state) {
    return descriptions.at(state);
}

void Location::setDescription(string state, string desc) {
    descriptions.insert(pair<string, string>(state, desc));
}

// Sets the description for a specific skill level
void Location::setDescriptionSkillLevel(int level, string desc) {
    descriptions.insert(pair<string, string>(to_string(level), desc));
}

string Location::getDescriptionSkillLevel(int level) {
    return descriptions.at(to_string(level));
}

bool Location::hasDescriptionSkill(int level) {
    return descriptions.count(to_string(level));
}

void Location::denyEntry(Direction dir, string item_required) {
    denied.insert(pair<Direction, string>(dir, item_required));
}

void Location::allowEntry(Direction dir) {
    denied.erase(dir);
}

bool Location::deniedEntry(Direction dir) {
    return denied.count(dir);
}

string Location::requiresItem(Direction dir) {
    return denied.at(dir);
}

Location* Location::getLocation(Direction dir) {
    return locations[dir];
}

void Location::setDirection(Direction dir, Location* loc) {
    bool reEntry = true;
    if (locations[dir] != NULL)
            cout << "There's already a room in this direction!" << endl;
    locations[dir] = loc;
    if (reEntry) {
        Direction opposite = oppositeDirection(dir);
        if (loc->locations[opposite] != NULL)
            cout << "There's already a room in the opposite direction!" << endl;
        loc->locations[opposite] = this;
    }
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
        case UP:
            return DOWN;
        case DOWN:
            return UP;
        default:
            return NUM_DIRECTIONS;
    }
    //return NUM_DIRECTIONS; // IDK what else to return
}

void Location::addItem(Item* item) {
    items.push_back(item);
}

void Location::removeItem(Item* item) {
    // find location of item
    vector<Item*>::iterator it;
    it = std::find(items.begin(), items.end(), item);
    items.erase(it);
    //return item;
}

void Location::addPerson(Person* person) {
    people.push_back(person);
}

Person* Location::removePerson(Person* person) {
	return NULL;
}

vector<Item*>* Location::getItems() {
    return &items;
}