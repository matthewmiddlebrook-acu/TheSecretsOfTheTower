#include "Command.h"
#include <vector>
#include <typeinfo>
#include <iostream>
#include <algorithm>

//enum Direction{NORTH, SOUTH, EAST, WEST, UP, DOWN, NUM_DIRECTIONS};
vector<std::string> DIR = {"NORTH", "EAST", "WEST", "UP", "DOWN"};

std::map <std::string, std::string> MANUAL = {
    { "MENU COMMANDS:\n", ""},
    { "QUIT","\nManual QUIT:\n\tDescription: Exits the game\n\tExample: QUIT\n\n" },
    { "MAN", "\nManual: MAN\n\tDescription: Displays the manual for the game or a specified command. \
             \n\tUsage: MAN (displays game manual)\n\t       MAN (COMMAND) (displays manual for specified command) \
             \n\tExample: MAN GO\n\n" },
    { "GO",  "\nManual: GO\n\tDescription: Moves the player in a specified direction.\n\tUsage: GO (DIRECTION) \
             \n\tPossible Directions: [NORTH, EAST, SOUTH, WEST, UP, DOWN]\n\tExample: GO NORTH\n\n" },
    { "TAKE","\nManual: TAKE:\n\n" },
    { "INVENTORY", "\nManual: Inventory\n\n" }
};


// returns the corresponding direction
// if the string "direciton" does not have a corresponding direction return 
//  NUM_DIRECTIONS (last element in enum).
Direction convertStringToEnum(std::string direction) {
    if (direction == "NORTH")
        return NORTH;
    else if (direction == "EAST")
        return EAST;
    else if (direction == "SOUTH")
        return SOUTH;
    else if (direction == "WEST")
        return WEST;
    else if (direction == "UP")
        return UP;
    else if (direction == "DOWN")
        return DOWN;

    return NUM_DIRECTIONS;
}


// BASE
Handler::Handler() { next = NULL; }
void Handler::add(Handler* n) {
    if (next)
        next->add(n);       
    else
        next = n;
}
void Handler::handle(vector<string>* input) {
    if (next)
        next->handle(input);
    else
        std::cout << "You cannot do that.\n\n"; 
}

/* MENU COMMANDS: QUIT, MAN */
void QUIT::handle(vector<string>* input) {
    /*
        check if command is "QUIT"
            check if command is used correcly
                calculations
            if not output manual for command
        if not pass command to next handler
    */
    if (input->at(0) == "QUIT")  {
        if (input->size() != 1)
             std::cout << MANUAL["QUIT"];
        else 
            exit(EXIT_SUCCESS);
    }
    else
        Handler::handle(input);
}

void MAN::handle(vector<string>* input) {
    /*
        check if command is "MAN"
            check if command is calling MAN or MAN ___
                if MAN output manual
                if MAN ___ output manual for ___
            if not output manual for command
        if not pass command to next handler
    */
    if (input->at(0) == "MAN")  {
        if (input->size() == 1)
            std::cout << "This will output the manual.\n\n";
            //outputManual();
        else if (input->size() == 2)  {
            std::map<std::string,std::string>::iterator i = MANUAL.find(input->at(1));
            if (i != MANUAL.end())
                 std::cout << i->second;
            else 
                std::cout << MANUAL["MAN"];
        }
    }
    else
        Handler::handle(input);
}

/* LOCATION COMMANDS: GO, LOOK */
void GO::handle(vector<string>* input) {
    /*
    check if command is "GO"
        check if command is used correctly
            - get player instance
            - get player location
            - check if given direction is permissible given the player's location
    */
    if (input->at(0) == "GO") {
        if (input->size() != 2) 
            std::cout << MANUAL["GO"];
        else if (input->size() == 2) {
            std::vector<string>::iterator i;
            i = find(DIR.begin(), DIR.end(), input->at(1));
            if (i == DIR.end())
                std::cout << MANUAL["GO"];
            else {
                std::cout << "GO passed\n\n";
                Player* player = Player::getPlayer();
                if (!(player->move(convertStringToEnum(input->at(1)))))
                    std::cout << "You cannot do that.\n\n";
            }
        }
    }
    else
        Handler::handle(input);
}

/* ACTION COMMANDS: TAKE */
void TAKE::handle(vector<std::string>* input) {
    if (input->at(0) == "TAKE") {
        if (input->size() != 2) 
            std::cout << MANUAL["TAKE"];
        else {
            vector<Item*>* locationItems = Player::getPlayer()->getLocation()->getItems();
            for (unsigned int i = 0; i < locationItems->size(); i++) {
                Item* item = locationItems->at(i);
                if (item->getName() == input->at(1)) {
                    //std::cout << "ITEM TAKEN" << std::endl;
                    Player::getPlayer()->getLocation()->removeItem(item);
                    Player::getPlayer()->addItem(item);

                    //Player::getPlayer()->addItem(Player::getPlayer()->getLocation()->removeItem(locationItems->at(i)));
                }
                //std::cout << locationItems->at(i)->getName() << std::endl;
            }
            
        }
        //std::cout << "TAKE passed" << std::endl;
    }
    else
        Handler::handle(input);
}

void INVENTORY::handle(vector<std::string>* input) {
    if (input->at(0) == "INVENTORY") {
        if (input->size() != 1)
            std::cout << MANUAL["INVENTORY"];
        else {
            std::cout << "INVENTORY:\n";
            vector<Item*>* inventory = Player::getPlayer()->getItems();
            for (unsigned int i = 0; i < inventory->size(); i++)
                std::cout << inventory->at(i)->getName() << std::endl;
        }
        //std::cout << "INVENTORY passed" << std::endl;
        
    }
    else
        Handler::handle(input);
}

void INFO::handle(vector<std::string>* input) {
    if (input->at(0) == "INFO") {
        std::cout << "Location: " << Player::getPlayer()->getLocation()->getName() << std::endl;
        std::cout << "Location Inventory: ";
        for (unsigned int i = 0; i < Player::getPlayer()->getLocation()->getItems()->size(); i++)
            std::cout <<  Player::getPlayer()->getLocation()->getItems()->at(i)->getName() << " ";
        std::cout << "\n";
        std::cout << "Player Inventory: ";
        for (unsigned int i = 0; i < Player::getPlayer()->getItems()->size(); i++)
            std::cout <<  Player::getPlayer()->getItems()->at(i)->getName() << " ";
        std::cout << "\n\n";
    }
    else
        Handler::handle(input);
}

