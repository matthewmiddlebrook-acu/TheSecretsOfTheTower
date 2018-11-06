#ifndef MANUAL_H
#define MANUAL_H

#include <map>
#include <iterator>
#include "command.h"
#include <iostream>



std::map <std::string, std::string> MANUAL = {
    { "MENU COMMANDS:\n", ""},
    { "QUIT","\nManual QUIT:\n\tDescription: Exits the game\n\tExample: QUIT\n\n" },
    { "MAN", "\nManual: MAN\n\tDescription: Displays the manual for the game or a specified command. \
             \n\tUsage: MAN (displays game manual)\n\t       MAN (COMMAND) (displays manual for specified command) \
             \n\tExample: MAN GO\n\n" },
    { "GO",  "\nManual: GO\n\tDescription: Moves the player in a specified direction.\n\tUsage: GO (DIRECTION) \
             \n\tPossible Directions: [NORTH, EAST, SOUTH, WEST, UP, DOWN]\n\tExample: GO NORTH\n\n" },
    { "TAKE","\nManual: TAKE:\n\n" }
};


<<<<<<< HEAD
std::string outputManual() {
}

#endif
=======
//std::string outputManual() {
//}
>>>>>>> 9c4fdc05cecae2f7e4c3f62730da6c052c5f9adf
