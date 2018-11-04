#include "GameObject.cpp"
#include "Location.cpp"
#include "Player.cpp"
#include "command.cpp"

#include <string>
#include <iostream>
#include <sstream>
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

    Player *player = Player::getPlayer();
    player->setLocation(&a);


    QUIT root;
    MAN m1;

    //GO l1;
    //LOOK l2;

    //TAKE a1;

   root.add(&m1);
   // root.add(&l1);
   // root.add(&l2);
   // root.add(&a1);

    

    while (true) {
        try {
            string input;
            getline(cin, input);
            vector<string> v;
            stringstream ss(input);

            for (string word; ss >> word; ) {
                v.push_back(word);
            }

            if (input == "")
                throw "Please enter valid input. If you have any questions type MAN.";


            root.handle(&v);


        }
        catch(const char* msg) {
            cout << msg << endl;
        }
        
    }
}
