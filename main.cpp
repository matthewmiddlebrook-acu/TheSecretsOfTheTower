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
    Location start("Starting Room", "Player starts the game here.");
    Location west("Beginning", "This room is west.");
    Location east("Beginning", "This room is east.");


    start.setDirection(WEST, &west);
    start.setDirection(EAST, &east);

    Item sword("sword", "excalibur");
    Item dagger("dagger", "whitefang");
    start.addItem(&sword);
    start.addItem(&dagger);

    Player *player = Player::getPlayer();
    player->setLocation(&start);


    QUIT root;
    MAN m1;

    GO l1;

    TAKE a1;

    INVENTORY a2;
    INFO a3;

   root.add(&m1);
   root.add(&l1);
   root.add(&a1);
   root.add(&a2);
   root.add(&a3);

    

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

            //cout <<"\n\n";
            //Location* location = player->getLocation();
           // cout << location->getDescription() << endl;
            //vector<Item*>* itemsInRoom = location->getItems();
            //for(unsigned int i = 0; i < itemsInRoom->size(); i++) 
            //cout << itemsInRoom->at(i)->getName() << endl;


            root.handle(&v);

 


        }
        catch(const char* msg) {
            cout << msg << endl;
        }
        
    }
}



/*

starting description















*/
