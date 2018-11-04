#include <map>
#include <iterator>
#include "command.h"
#include <iostream>



std::map <std::string, std::string> MANUAL = {
    { "MENU COMMANDS:\n", ""},
    { "QUIT", "\tQUIT MAN\n\n" },
    { "MAN", "\tMAN MAN\n\n" },
    { "GO", "\tGO MAN\n\n" },
};



std::string outputManual() {
    std::map<std::string, std::string>::iterator i = MANUAL.begin();
    while (i != MANUAL.end()) {
        std::string com = i->first;
        std::string man = i->second;

        std::cout << com + ":\n" << man;

        i++;
    }
}
