#include "Command.h"
#include <vector>
#include <typeinfo>
#include <iostream>
#include <algorithm>

//enum Direction{NORTH, SOUTH, EAST, WEST, UP, DOWN, NUM_DIRECTIONS};
vector<std::string> DIR = {"NORTH", "SOUTH", "EAST", "WEST", "UP", "DOWN"};

std::map <std::string, std::string> MANUAL = {
    { "MENU COMMANDS:\n", ""},
    { "QUIT","\nManual QUIT:\n\tDescription: Exits the game\n\tExample: QUIT\n\n" },
    { "MAN", "\nManual: MAN\n\tDescription: Displays the manual for the game or a specified command. \
             \n\tUsage: MAN (displays game manual)\n\t       MAN (COMMAND) (displays manual for specified command) \
             \n\tExample: MAN GO\n\n" },
    { "GO",  "\nManual: GO\n\tDescription: Moves the player in a specified direction.\n\tUsage: GO (DIRECTION) \
             \n\tPossible Directions: [NORTH, EAST, SOUTH, WEST, UP, DOWN]\n\tExample: GO NORTH\n\n" },
    { "TAKE","\nManual: TAKE:\n\n" }
};

Direction convert(std::string direction)
{
    /*switch(direction)
    {
        case "NORTH":
            return NORTH;
        case "EAST":
            return EAST;
        case "SOUTH":
            return SOUTH;
        case "WEST":
            return WEST;

        default
    }*/
    if (direction == "NORTH")
        return NORTH;
    else if (direction == "EAST")
        return EAST;
    else if (direction == "SOUTH")
        return SOUTH;
    else if (direction == "WEST")
        return WEST;
    
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
                // std::cout << "GO passed\n\n";
                Player* player = Player::getPlayer();
                if (!(player->move(convert(input->at(1)))))
                    std::cout << "You cannot do that.\n\n";
            }
        }
    }
    else
        Handler::handle(input);
}

/* ACTION COMMANDS: TAKE */
void TAKE::handle(vector<std::string>* input) {
    if (input->at(0) == "TAKE"){
        std::cout << "TAKE passed" << std::endl;
    }
    else
        Handler::handle(input);
}