#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <string>
#include <iomanip>

#include "Player.h"
#include "Location.h"

//HAVE NOT COVERED CASE WHERE USER ENTERS LONG STRING OF NOTHING



/* BASE HANDLER */
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

/* ACTION COMMANDS: DO, TAKE, INVENTORY */
class GO : public Handler {
    public:
        void handle(vector<std::string>* input);
};
class TAKE : public Handler {
    public:
        void handle(vector<std::string>* input);
};
class INVENTORY : public Handler {
    public:
        void handle(vector<std::string>* input);
};
class SKILLS : public Handler {
    public:
        void handle(vector<std::string>* input);
};

class TALK :  public Handler {
    public:
        void handle(vector<std::string>* input);
};

/* DEBUG COMMANDS: INFO */
class INFO : public Handler {
    public:
        void handle(vector<std::string>* input);
};


#endif