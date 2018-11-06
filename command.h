#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include <map>
#include <iterator>

#include "Player.h"
#include "Location.h"

//HAVE NOT COVERED CASE WHERE USER ENTERS LONG STRING OF NOTHING


/* 
BASE HANDLER: abstract class
next: pointer to the next handler in the chain
      init as NULL
*/
class Handler {
    public:
        Handler();
        void add(Handler* n);
        virtual void handle(vector<std::string>* input);
    private:
        Handler* next;
};


/* MENU COMMANDS: QUIT, MAN */

class QUIT : public Handler {
    public:
        void handle(vector<std::string>* input);
};

class MAN : public Handler {
    public:
        void handle(vector<std::string>* input);
};

/* LOCATION COMMANDS: GO, LOOK */

class GO : public Handler {
    public:
        void handle(vector<std::string>* input);
};

/*class LOOK : public Handler {
    public:
        void handle(std::string s);
};*/

/* ITEM COMMANDS: TAKE */

class TAKE : public Handler {
    public:
        void handle(vector<std::string>* input);
};

#endif