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

Item* Location::removeItem(Item* item) {
	return NULL;
}

void Location::addPerson(Person* person) {
    people.push_back(person);
}

Person* Location::removePerson(Person* person) {
	return NULL;
}

/*Location* Location::createLocations() {
    Location entrance("The Entrance", "The Entrance\nYou are standing inside a strange building. The room is dimly lit, and you hear strange grumbling noises coming from the EAST. The only object in the room is a potato, lying on the floor. It seems very inviting for some reason.");

    Item potato("Potato", "It looks delicious!");
    entrance.addItem(&potato);

    Location elevator_room("The Elevator Room", "You see a statue of a person, with their mouth wide open. Next to the statue, you see an Elevator. The statue seems to be making a grumbling noise, as if it was hungry. Weird.");

    Item statue("Strange Statue", "A strange looking statue of a man, with its mouth agape. It looks hungry");
    elevator_room.addItem(&statue);

    entrance.setDirection(EAST, &elevator_room);

    Location test("Elevator - Floor 1");

    elevator_room.setDirection(EAST, &test);


    Location test2("Elevator - Floor 2");

    test.setDirection(UP, &test2);


    Location room1("Test room", "Blah blah");

    test2.setDirection(SOUTH, &room1);


    Location room2("Test room 2");

    room1.setDirection(WEST, &room2);

    
    Location room3("Test room 3");

    room2.setDirection(NORTH, &room3);

    // Return the root location that the player will start in
    return &entrance;
}*/