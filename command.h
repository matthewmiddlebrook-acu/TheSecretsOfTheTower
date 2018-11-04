#pragma once

#include <iostream>
#include <vector>
#include "Player.h"
#include "Location.h"
#include "Manual.h"


/* 
BASE HANDLER: abstract class
next: pointer to the next handler in the chain
      init as NULL
*/
class Handler {
    public:
        Handler();
        void add(Handler* n);
        virtual void handle(vector<string>* input);
    private:
        Handler* next;
};


/* MENU COMMANDS: QUIT, MAN */

class QUIT : public Handler {
    public:
        void handle(vector<string>* input);
};

class MAN : public Handler {
    public:
        void handle(vector<string>* input);
};

/* LOCATION COMMANDS: GO, LOOK */

class GO : public Handler {
    public:
        void handle(vector<string>* input);
};

/*class LOOK : public Handler {
    public:
        void handle(std::string s);
};*/

/* ITEM COMMANDS: TAKE */ /*

class TAKE : public Handler {
    public:
        void handle(std::string s);
};*/
