#ifndef COMMAND_H
#define COMMAND_H

#include <iostream>
#include <vector>
#include <map>
#include <iterator>

#include "Player.h"
#include "Location.h"

//HAVE NOT COVERED CASE WHERE USER ENTERS LONG STRING OF NOTHING


/* BASE HANDLER:
    ~ add: adds handler to list
    ~ handle: specified class handles request
        if class is unable to handle the request, pass requst to next class in the chain
    ~ next: pointer to the next handler in the chain
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

/* LOCATION COMMANDS: GO */
class GO : public Handler {
    public:
        void handle(vector<std::string>* input);
};

#endif

/* ACTION COMMANDS: TAKE */
class TAKE : public Handler {
    public:
        void handle(vector<std::string>* input);
};
class INVENTORY : public Handler {
    public:
        void handle(vector<std::string>* input);
};
class INFO : public Handler {
    public:
        void handle(vector<std::string>* input);
};