#pragma once

#include <iostream>
#include "Player.h"
#include "Location.h"


/* 
BASE HANDLER: abstract class
next: pointer to the next handler in the chain
      init as NULL
*/
class Handler {
    public:
        Handler();
        void add(Handler* n);
        virtual void handle(std::string s);

    private:
        Handler* next;
};


/* MENU COMMANDS: QUIT, MAN */

class QUIT : public Handler {
    public:
        void handle(std::string s);
};

class MAN : public Handler {
    public:
        void handle(std::string s);
};

/* LOCATION COMMANDS: GO, LOOK */

class GO : public Handler {
    public:
        void handle(std::string s);
};

class LOOK : public Handler {
    public:
        void handle(std::string s);
};

/* ITEM COMMANDS: TAKE */

class TAKE : public Handler {
    public:
        void handle(std::string s);
};
