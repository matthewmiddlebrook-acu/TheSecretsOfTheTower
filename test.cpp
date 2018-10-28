#include "Location.cpp"

#include <iostream>
using namespace std;

// This file tests creating locations, assigning a location in a direction, and getting the location in that direction

int main() {
    Location a("MBB", "Mabee Business Building");
    Location b("BSB", "Onstead-Packer Biblical Studies Building");

    a.setDirection(NORTH, &b);
    Location* north = a.getLocation(NORTH);
    cout << "North of " << a.getName() << ", The " << a.getDescription()
         << ", is " << north->getName() << ", The " << north->getDescription() << "." << endl;
}