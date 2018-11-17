#include "GameObject.h"
#include "Location.h"
#include "Player.h"
#include "Command.h"
#include "PrintColor.h"

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

// This file tests creating locations, assigning a location in a direction, and getting the location in that direction

int main()
{
    // I will move these locations to another file later...
    // I'd love to someday add a way to add html-like tags to the strings to make text a certain color, or add a time delay at certain parts
    
    /* INIT LOCATIONS */
    Location start("The Entrance", "The room is barely lit by moonlight shining through the large glass arches above you, and you hear grumbling noises coming from the WEST, towards an elevator. As you look around, you realize that you are in the Atrium of the Business Building at ACU.");
    Location west("Elevator Area", "Next to the elevator, you see a statue of a person, with their mouth wide open. Looking closer, it appears to have the face of Dr. Prather. He looks absolutely terrified. And hungry.\nThe statue seems to be making a grumbling noise. Weird.");
    Location south("Main Atrium", "There's a faint smell of ... bean dip ... in the air. No, you're not going crazy. Probably not, at least.\nBesides the obvious furniture, the only object of interest in the room is a potato, lying on the floor. It seems inviting. Oddly inviting.");
    Location hallway("Downstairs Hallway - Near Bathroom", "Facing you are the bathrooms. In the hallway, you see many classrooms, yet there's no one to be found. In the distance, you hear singing.\nLying on the ground, you see a can of the strongest smelling bean dip you have ever smelled. To the NORTH, the hallway continues, and to the SOUTH, you see the Griggs Center.");
    Location griggs("The Griggs Center", "On one of the tables, there lies a notebook");
    Location north_hallway("Downstairs Hallway - Near Store", "Next to you is the store that nobody goes to. To the EAST is a classroom, where you hear the voice of Dr. Prather teaching.");
    Location classroom("Dr. Prather's Classroom", "Dr. Prather stops talking, and stares at you as you enter the classroom.\n\"Thank you for bringing my notebook!\" he exclaims. \"I was very hungry!\"\n\nThank you for playing the demo of our game! This was brief look into The Secrets of the Tower. In the full game, there will be much more to do and explore in and out of COBA. Story is subject to change. Please type \"QUIT\" to quit the game.");

    start.setDescription("START", "You awake standing inside a strange building.");

    start.setDirection(WEST, &west);
    start.setDirection(SOUTH, &south);

    south.setDirection(WEST, &hallway);

    hallway.setDirection(NORTH, &north_hallway);
    hallway.setDirection(SOUTH, &griggs);

    north_hallway.setDirection(EAST, &classroom);

    /* INIT ITEMS */
    Item potato("POTATO", "It looks delicious!");
    south.addItem(&potato);

    Item beanDip("CAN", "A singing can of bean dip. On the lid, it says: \"Bean Dip: The Musical!\"");
    hallway.addItem(&beanDip);

    Item notebook("NOTEBOOK", "A notebook perfect for a class with Dr. Prather");
    griggs.addItem(&notebook);

    north_hallway.denyEntry(EAST, "NOTEBOOK");
    north_hallway.setDescription("NOTEBOOK", "You can't enter a classroom without a notebook! Dr. Prather would be disappointed with you!");

    /* INIT HANDLERS */
    QUIT root;
    MAN m1;
    GO a1;
    TAKE a2;
    INVENTORY a3;
    INFO d1;

    root.add(&m1);
    root.add(&a1);
    root.add(&a2);
    root.add(&a3);
    root.add(&d1);

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

