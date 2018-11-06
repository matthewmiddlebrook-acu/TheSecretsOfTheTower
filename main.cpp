#include "GameObject.h"
#include "Location.h"
#include "Player.h"
#include "Command.h"

#include <string>
#include <iostream>
#include <sstream>
using namespace std;


// This file tests creating locations, assigning a location in a direction, and getting the location in that direction

int main() {

    /* INIT LOCATIONS */
    Location start("Starting Room", "Player starts the game here.");
    Location west("Beginning", "This room is west.");
    Location east("Beginning", "This room is east.");

    start.setDirection(WEST, &west);
    start.setDirection(EAST, &east);

    /* INIT ITEMS */
    Item sword("SWORD", "excalibur");
    Item dagger("DAGGER", "whitefang");
    Item bow("BOW", "ashe");
    Item staff("STAFF", "mordrid");
    start.addItem(&sword);
    start.addItem(&dagger);
    start.addItem(&bow);
    start.addItem(&staff);

    /* INIT PLAYER */
    Player *player = Player::getPlayer();
    player->setLocation(&start);

    /* INIT COMMAND LINE */
    QUIT root;
    MAN m1;
    GO a1;
    TAKE a2;
    INVENTORY a3;
    // USE a4;
    INFO d1;

    root.add(&m1);
    root.add(&a1);
    root.add(&a2);
    root.add(&a3);
    root.add(&d1);

    while (true) {
        try {
            string input;
            cout << "~ ";
            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(), ::toupper);
            vector<string> v;
            stringstream ss(input);

            for (string word; ss >> word;)
                v.push_back(word);

            if (input == "") //iswhite
                throw "Please enter valid input. If you have any questions type MAN.";
            root.handle(&v);
        }
        catch(const char* msg) {
            cout << msg << endl;
        }
    }
}

