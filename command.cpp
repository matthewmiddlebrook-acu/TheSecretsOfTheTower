#include "Command.h"
#include "PrintColor.h"

using namespace std;

/*map <string, string> MANUAL = {
    { "MENU COMMANDS:\n", ""},
    { "QUIT","\nManual QUIT:\n\tDescription: Exits the game\n\tExample: QUIT\n\n" },
    { "MAN", "\nManual: MAN\n\tDescription: Displays the manual for the game or a specified command. \
             \n\tUsage: MAN (displays game manual)\n\t       MAN (COMMAND) (displays manual for specified command) \
             \n\tExample: MAN GO\n\n" },
    { "GO",  "\nManual: GO\n\tDescription: Moves the player in a specified direction.\n\tUsage: GO (DIRECTION) \
             \n\tPossible Directions: [NORTH, EAST, SOUTH, WEST, UP, DOWN]\n\tExample: GO NORTH\n\n" },
    { "TAKE","\nManual: TAKE:\n\n" },
    { "INVENTORY", "\nManual: Inventory\n\n" }
};*/

map<string,string> MANUAL = {
    { "QUIT", "Exits the game." },
    { "GO", "Moves the player in a specified direction." },
    { "TAKE", "Picks up an item." },
    { "INVENTORY", "Shows player's current inventory." }
};

vector<string> DIR = {"NORTH", "SOUTH", "EAST", "WEST", "UP", "DOWN"};

// returns the corresponding direction
// if the string "direciton" does not have a corresponding direction return 
// NUM_DIRECTIONS (last element in enum).
Direction convertStringToEnum(std::string direction) {
    if (direction == "NORTH")
        return NORTH;
    else if (direction == "EAST")
        return EAST;
    else if (direction == "SOUTH")
        return SOUTH;
    else if (direction == "WEST")
        return WEST;
    else if (direction == "UP")
        return UP;
    else if (direction == "DOWN")
        return DOWN;

    return NUM_DIRECTIONS;
}

/* BASE HANDLER */
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
        cout << endl << "Please enter a valid command." << endl << endl; 
}

/* MENU COMMANDS: QUIT, MAN */

// exits the game =
void QUIT::handle(vector<string>* input) {
    if (input->at(0) == "QUIT")  {
        if (input->size() != 1)
             cout << MANUAL["QUIT"];
        else 
            exit(EXIT_SUCCESS);
    }
    else
        Handler::handle(input);
}

// no "arguements": ouputs game manual
// one "arguement": outputs command manual
void MAN::handle(vector<string>* input) {
    if (input->at(0) == "MAN") {
        if (input->size() == 1) {
            cout << endl << "Manual:" << endl << "----------------------" << endl;
            for (map<string,string>::iterator it = MANUAL.begin(); it != MANUAL.end(); it++)
                cout << it->first << ":  " << it->second << endl;
            cout << "----------------------" << endl << endl;
        }
        else if (input->size() == 2) {
            map<string,string>::iterator i = MANUAL.find(input->at(1));
            if (i != MANUAL.end()) {
                cout << endl << "Manual: " + input->at(1) << endl << "----------------------" << endl << i->second << endl
                << "----------------------" << endl << endl;
            }
            else {
                cout << endl << "Please enter a valid command." << endl << endl; // MANUAL["MAN"];
            }
                
        }
    }
    else
        Handler::handle(input);
}

/* ACTION COMMANDS: GO, TAKE, INVENTORY, USE */

// moves player, if possible, from current room to another room in the specified direction
void GO::handle(vector<string>* input) {
    if (input->at(0) == "GO") {
        if (input->size() != 2) 
            cout << endl << "Invalid input." << endl << endl; // + MANUAL["GO"];
        else {
            vector<string>::iterator it = find(DIR.begin(), DIR.end(), input->at(1));
            if (it == DIR.end())
                cout << endl << "Please enter a valid direction. Possible directions are: NORTH, SOUTH, EAST, WEST, UP, and DOWN." << endl << endl; // MANUAL["GO"];
            else
                if (!(Player::getPlayer()->move(convertStringToEnum(input->at(1)))))
                    cout << endl << "There's nothing in the direction." << endl << endl;
                else {
                    cout << PrintColor(Player::getPlayer()->getLocation()->getName(), B_CYAN) << endl;
                    cout << endl;
                    cout << Player::getPlayer()->getLocation()->getDescription() << endl;
                }
        }
    }
    else
        Handler::handle(input);
}

// remvoves specified item from location and adds it to player's inventory
void TAKE::handle(vector<string>* input) {
    if (input->at(0) == "TAKE") {
        if (input->size() != 2) 
            cout << "Invlaid input." << endl; // MANUAL["TAKE"];
        else {
            for (unsigned int i = 0; i <  Player::getPlayer()->getLocation()->getItems()->size(); i++) {
                Item* item = Player::getPlayer()->getLocation()->getItems()->at(i);
                if (item->getName() == input->at(1)) {
                    Player::getPlayer()->getLocation()->removeItem(item);
                    Player::getPlayer()->addItem(item);
                }
            }
        }
    }
    else
        Handler::handle(input);
}

// output current items in player inventory
void INVENTORY::handle(vector<string>* input) {
    if (input->at(0) == "INVENTORY") {
        if (input->size() != 1)
            cout << "Invalid input." << endl; // MANUAL["INVENTORY"];
        else {
            cout << endl << "INVENTORY:" << endl << "----------------------" << endl;
            if (Player::getPlayer()->getItems()->size() == 0)
                cout << "There are currently no items in your inventory.";
            else
                for (unsigned int i = 0; i < Player::getPlayer()->getItems()->size(); i++) {
                    if (!(i % 3) && i != 0)
                        cout << endl;
                    cout << Player::getPlayer()->getItems()->at(i)->getName() << "\t";
                }
            cout << endl << "----------------------" << endl << endl;
        } 
    }
    else
        Handler::handle(input);
}

/* DEBUG COMMANDS: INFO */

// output's current location, location iventory, and player inventory
void INFO::handle(vector<string>* input) {
    if (input->at(0) == "INFO") {
        cout << "Location: " << Player::getPlayer()->getLocation()->getName() << std::endl;
        cout << "Location Inventory: ";
        for (unsigned int i = 0; i < Player::getPlayer()->getLocation()->getItems()->size(); i++)
            cout <<  Player::getPlayer()->getLocation()->getItems()->at(i)->getName() << " ";
        cout << endl;
        cout << "Player Inventory: ";
        for (unsigned int i = 0; i < Player::getPlayer()->getItems()->size(); i++)
            std::cout <<  Player::getPlayer()->getItems()->at(i)->getName() << " ";
        cout << endl << endl;
    }
    else
        Handler::handle(input);
}