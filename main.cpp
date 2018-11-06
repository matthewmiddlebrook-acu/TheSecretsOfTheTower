#include "GameObject.h"
#include "Location.h"
#include "Player.h"
#include "Command.h"
#include "PrintColor.h"

#include <string>
#include <iostream>
#include <sstream>
using namespace std;


// This file tests creating locations, assigning a location in a direction, and getting the location in that direction

int main() {
    Location start("The Entrance", "You are standing inside a strange building. The room is dimly lit, and you hear strange grumbling noises coming from the WEST.\nThe only object in the room is a potato, lying on the floor. It seems very inviting for some reason.");
    Location west("The Elevator Room", "You see a statue of a person, with their mouth wide open. Next to the statue, you see an Elevator.\nThe statue seems to be making a grumbling noise, as if it was hungry. Weird.");
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

   cout << PrintColor(player->getLocation()->getName(), BLUE) << endl;
   cout << endl;
   cout << player->getLocation()->getDescription() << endl;

   while (true)
   {
       try
       {
            string input;
            cout << "~ ";

            PrintColor::setOutputColor(MAGENTA);

            getline(cin, input);
            vector<string> v;
            stringstream ss(input);

            PrintColor::setOutputColor(BLACK);


            for (string word; ss >> word;)
            {
                v.push_back(word);
            }

            if (input == "")
                throw "Please enter valid input. If you have any questions type MAN.";

            root.handle(&v);

            Location *location = player->getLocation();
            cout << PrintColor(location->getName(), BLUE) << endl;
            cout << endl;
            cout << location->getDescription() << endl;
       }
       catch (const char *msg)
       {
           cout << msg << endl;
       }
        
    }
}



/*

starting description















*/
