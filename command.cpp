#pragma once

#include "command.h"
#include "Player.h"
#include <vector>
#include <typeinfo>


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
        std::cout << "You cannot do that."; 
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

/* LOCATION COMMANDS: GO, LOOK 
void GO::handle(std::string s) {
    if (s == "GO") {
        std::cout << "GO passed" << std::endl;
         /* PSEUDO
         get current location of player
         check to see if direction chosen is valid 
            move player 
            return "you cannot do that";
        */

       /* ACTUAL
       Player* player = Player::getPlayer();
       Location* location = player->getLocation();
       if (location->checkDirection()) {
           // move player
       }
       else {
           std::cout << "You cannot do that." << std::endl;
       }

       

    }
    else
        Handler::handle(s);
}

void LOOK::handle(std::string s) {
    if (s == "LOOK") {
        std::cout << "LOOK passed" << std::endl;
        /*
        get current locaiton of player
        output description of current location
        
    }
    else
        Handler::handle(s);
}

/* ACTION COMMANDS: TAKE */ /*
void TAKE::handle(std::string s) {
    if (s == "TAKE"){
        std::cout << "TAKE passed" << std::endl;
    }
    else
        Handler::handle(s);
}*/