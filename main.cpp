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
    Location start("Beginning", "Player starts the game here.");
    Location west("Beginning", "This room is west.");
    Location east("Beginning", "This room is east.");


    start.setDirection(WEST, &west);
    start.setDirection(EAST, &east);

    Player *player = Player::getPlayer();
    player->setLocation(&start);


    QUIT root;
    MAN m1;

    GO l1;
    //LOOK l2;

    //TAKE a1;

   root.add(&m1);
   root.add(&l1);
   // root.add(&l2);
   // root.add(&a1);

    

    while (true) {
        try {
            string input;
            cout << "~ ";
            getline(cin, input);
            vector<string> v;
            stringstream ss(input);

            for (string word; ss >> word; ) {
                v.push_back(word);
            }

            if (input == "")
                throw "Please enter valid input. If you have any questions type MAN.";


            root.handle(&v);

            Location* location = player->getLocation();
            cout << location->getDescription();


        }
        catch(const char* msg) {
            cout << msg << endl;
        }
        
    }
}



/*

starting description















*/
