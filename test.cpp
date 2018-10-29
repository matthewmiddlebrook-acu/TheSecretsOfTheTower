#include "GameObject.cpp"
#include "Location.cpp"

#include <string>
#include <iostream>
using namespace std;

// This file tests creating locations, assigning a location in a direction, and getting the location in that direction

int main() {
    Location a("MBB", "Mabee Business Building");
    Location b("BSB", "Onstead-Packer Biblical Studies Building");

    a.setDirection(NORTH, &b);
    a.setAlternateNames({"COBA", "Mabee"});

    // Check if a building in a direction exists
    if (a.checkDirection(NORTH)) {
        Location* north = a.getLocation(NORTH);
        cout << "North of " << a.getName() << ", The " << a.getDescription()
            << ", is " << north->getName() << ", The " << north->getDescription() << "." << endl;
    }

    // Checks to make sure if automatic set opposite direction is working
    if (b.checkDirection(SOUTH)) {
        Location *south = b.getLocation(SOUTH);
        cout << "South of " << b.getName() << " is " << south->getName() << "." << endl;
    }

    // Check if a building in a direction does not exist
    if (!a.checkDirection(SOUTH))
        cout << "There is no building south of " << a.getName() << "." << endl;

    if (a.checkName("mabee"))
        cout << "Name is valid." << endl;
}