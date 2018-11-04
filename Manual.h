#include <map>
#include <iterator>
#include "command.h"
#include <iostream>



std::map <std::string, std::string> MANUAL = {
    { "MENU COMMANDS:\n", ""},
    { "QUIT", "\tQUIT MAN\n" },
    { "MAN", "\tMAN MAN\n" },
    { "GO", "\tGO MAN\n" },
};



std::string outputManual() {
    std::map<std::string, std::string>::iterator i = MANUAL.end();
    while (i != MANUAL.begin()) {
        std::string com = i->first;
        std::string man = i->second;

        std::cout << com + ":\n" << man;

        i--;
    }
}
