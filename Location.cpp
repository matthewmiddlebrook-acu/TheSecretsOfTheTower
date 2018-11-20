#include "Location.h"
#include "Player.h"
#include "ASCII.h"
#include "Python.h"

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

Location::Location(string name, string desc, bool _isClassroom, int req, vector<string> classes, int lowReq) :
    GameObject(name), classroom(_isClassroom), lowestReq(lowReq), classNames(classes)
{
    setDescription(desc);
    setRequiredSkill(req);
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
    return descriptions.count(to_string(level)); // if level is a key
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

void Location::doProject(int skill) {
    Player* player = Player::getPlayer();
    if (skill == 0) {
        cout << "You spent hours upon hours working on your Unity project looking up info on StackOverflow and the Unity API.\n" \
                "After hard work and sleepless nights, it is finally done! (except for that one bug you know is there,\n" \
                "but nobody could possibly find...)";
        Sleep(100);
        cout << player->getLocation()->getCompletionOutput() << endl;
        player->completeClass("ITC110");
        player->move(EAST);
        player->getLocation()->denyEntry(WEST, "You have already taken Intro to ITC");
    } else if (skill == 1) {
        if (classNames.at(skill) == "PROGRAMMING 1") {
            cout << endl;
            while (true) {

                if (helloWorld()) 
                    break;
                cout << endl << "Your code output does not match the expected output. Please try again." << endl << endl;
            }
            cout << endl << player->getLocation()->getCompletionOutput() << endl;
            player->completeClass("PROGRAMMING");
            player->move(WEST);
        } else if (classNames.at(skill) == "INTRO TO 3D MODELING") {
            donut();
            Sleep(100);
            cout << player->getLocation()->getCompletionOutput() << endl;
            player->completeClass("3D MODELING");
            player->move(WEST);
        } else if (classNames.at(skill) == "INTRO TO ANIMATION") {
            train();
            Sleep(100);
            cout << player->getLocation()->getCompletionOutput() << endl;
            player->completeClass("ANIMATION");
            player->move(EAST);
        } else if (classNames.at(skill) == "INTRO TO BUSINESS") {
            // Add business action
            Sleep(100);
            cout << player->getLocation()->getCompletionOutput() << endl;
            player->completeClass("BUSINESS");
            player->move(EAST);
        }
    } else {
        if (classNames.at(skill) == "PROGRAMMING 2") {
            cout << endl;
            while (true) {

                if (multTable()) 
                    break;
                cout << endl << "Your code output does not match the expected output. Please try again." << endl << endl;
            }
            cout << endl << player->getLocation()->getCompletionOutput() << endl;
            player->completeClass("PROGRAMMING");
            player->move(WEST);
            player->getLocation()->denyEntry(EAST, "You have already taken available Programming classes");
        } else if (classNames.at(skill) == "ADVANCED 3D MODELING") {
            anvil();
            Sleep(100);
            cout << player->getLocation()->getCompletionOutput() << endl;
            player->completeClass("3D MODELING");
            player->move(WEST);
            player->getLocation()->denyEntry(EAST, "You have already taken available 3D Modeling classes");
        } else if (classNames.at(skill) == "ADVANCED ANIMATION") {
            walk();
            Sleep(100);
            cout << player->getLocation()->getCompletionOutput() << endl;
            player->completeClass("ANIMATION");
            player->move(EAST);
            player->getLocation()->denyEntry(WEST, "You have already taken available Animation classes");
        } else if (classNames.at(skill) == "USELESS CLASS") {
            // Add business action
            cout << player->getLocation()->getCompletionOutput() << endl;
            player->completeClass("BUSINESS");
            player->move(EAST);
            player->getLocation()->denyEntry(WEST, "You have already taken available Business classes");
        }
    }
}