#pragma once

#include "command.h"
#include "Player.h"
#include <vector>
#include <typeinfo>
#include <iostream>
#include <algorithm>

//enum Direction{NORTH, SOUTH, EAST, WEST, UP, DOWN, NUM_DIRECTIONS};
vector<std::string> DIR = {"NORTH", "EAST", "WEST", "UP", "DOWN"};

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
            outputManual();
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
                Location* location = player->getLocation();
                if (!(player->move(convert(input->at(1)))))
                    std::cout << "You cannot do that.\n\n";
                //std::cout << location->getDescription();

                /* CANT TEST SINCE WE HAVE NO CONCRETE LOCATIONS
                Player* player = Player::getPlayer();
                std::vector<std::string>::iterator i;
                i = find(DIR.begin(), DIR.end(), input[1]);
                player->move(i);

                */ 
            }
        }
    }
    else
        Handler::handle(input);
}

/*
void LOOK::handle(std::string s) {
    if (s == "LOOK") {
        std::cout << "LOOK passed" << std::endl;
        /*
        get current locaiton of player
        output description of current location
        
    }
    else
        Handler::handle(s);
}*/

/* ACTION COMMANDS: TAKE */
void TAKE::handle(vector<std::string>* input) {
    if (input->at(0) == "TAKE"){
        std::cout << "TAKE passed" << std::endl;
    }
    else
        Handler::handle(input);
}