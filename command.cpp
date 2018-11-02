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
void Handler::handle(std::string s) {
    if (next)
        next->handle(s);
    else
        std::cout << "You cannot do that."; 
}

/* MENU COMMANDS: QUIT, MAN */
void QUIT::handle(std::string s) {
    if (s == "QUIT"){
        std::cout << "QUIT passed" << std::endl;
        exit(EXIT_SUCCESS);
    }
    else
        Handler::handle(s);
}

void MAN::handle(std::string s) {
    if (s == "MAN"){
        std::cout << "MAN passed" << std::endl;
    }
    else
        Handler::handle(s);
}

/* LOCATION COMMANDS: GO, LOOK */
void GO::handle(std::string s) {
    if (s == "GO") {
        std::cout << "GO passed" << std::endl;
    }
    else
        Handler::handle(s);
}

void LOOK::handle(std::string s) {
    if (s == "LOOK") {
        std::cout << "LOOK passed" << std::endl;
    }
    else
        Handler::handle(s);
}

/* ACTION COMMANDS: TAKE */
void TAKE::handle(std::string s) {
    if (s == "TAKE"){
        std::cout << "TAKE passed" << std::endl;
    }
    else
        Handler::handle(s);
}