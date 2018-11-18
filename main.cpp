#include "GameObject.h"
#include "Location.h"
#include "Player.h"
#include "Command.h"
#include "PrintColor.h"
#include "Init.h"

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

// This file tests creating locations, assigning a location in a direction, and getting the location in that direction
int main()
{
    Location start = initLocations();
    QUIT root = getHandlers();

    /* INIT PLAYER */
    Player *player = Player::getPlayer();
    player->setLocation(&start);

   
    cout << PrintColor("~  The Secrets of the Tower  ~", 244) << endl;

    cout << "This adventure game is created by Brighton Mica, Matthew Middlebrook, and Tommy Yates." << endl
         << "It is a draft. It has basic movement from room to room and the ability to pick up items." << endl
         << "The story for this draft is concerned with getting to class with your notebook." << endl
         << "The descriptions are not complete, but the functionality is present." << endl;

    cout << "\nGO:  Moves the player in a specified direction.\nINVENTORY:  Shows player's current inventory.\nQUIT:  Exits the game.\nTAKE:  Picks up an item.\n" << endl;

    cout << PrintColor(player->getLocation()->getName(), B_CYAN) << endl;
    cout << endl;

    cout << player->getLocation()->getDescription("START") << endl;

    cout << player->getLocation()->getDescription() << endl;

    while (true)
    {
        try
        {
            string input;
            cout << "~ ";

            PrintColor::setOutputColor(YELLOW);

            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(), ::toupper);
            vector<string> v;
            stringstream ss(input);

            PrintColor::setOutputColor(WHITE);

            for (string word; ss >> word;)
                v.push_back(word);

            if (input == "") //iswhite
                throw "Please enter valid input. If you have any questions type MAN.";

            root.handle(&v);

            // Location *location = player->getLocation();
            // cout << PrintColor(location->getName(), B_CYAN) << endl;
            // cout << endl;
            // cout << location->getDescription() << endl;
        }
        catch (const char *msg)
        {
            cout << msg << endl;
        }
    }
}

