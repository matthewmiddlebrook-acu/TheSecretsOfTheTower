#include "Command.h"
#include "PrintColor.h"




/*map<string,string> MANUAL = {
    { "QUIT", "Exits the game." },
    { "GO", "Moves the player in a specified direction." },
    { "TAKE", "Picks up an item." },
    { "INVENTORY", "Shows player's current inventory." }
};*/

string MANUAL = 
"SITC GUIDE:\n" \
"--------------------------------\n" \
"Our goal here at SITC is to help you get through\n" \
"college. DO assignments in classes to upgrade your\n" \
"SKILLS. Once you have completed a class by DOing a PROJECT\n" \
"(DO PROJECT) your SKILLS increase. Once you have enough SKILL\n" \
"points you will be able to take the final exam and,\n"
"if you pass, graduate from SITC.\n\n" \
"COMMANDS:\n" \
"---------------------\n" \
"GUIDE: outputs the SITC guide\n" \
"QUIT: exits the game\n" \
"GO: moves the player in a specified direction\n" \
"TAKE: adds an item to player's inventory\n" \
"INVENTORY: outputs the player's inventory\n" \
"SKILLS: outputs the player's skills\n" \
"TALK: the player talks to a random person in the room\n" \
"DO: the player does a project (DO PROJECT)\n\n" \
"The possible directions a player can GO are:\n" \
"NORTH, EAST, SOUTH, WEST, UP, DOWN\n\n" \
"The SKILL tree consists of:\n" \
"TYPING, LOGIC, SPEECH, CREATIVITY, CRAFTSMANSHIP, JAPANESE, INTELLIGENCE, SPIRITUALITY\n\n" \
"--------------------------------\n\n";


vector<string> DIR = {"NORTH", "SOUTH", "EAST", "WEST", "UP", "DOWN"};
vector<string> STRING_SKILLS = {"TYPING", "LOGIC", "SPEECH", "CREATIVITY", "CRAFTSMANSHIP", "JAPANESE", "INTELLIGENCE", "SPIRITUALITY"};

// returns the corresponding direction
// if the string "direction" does not have a corresponding direction return 
// NUM_DIRECTIONS (last element in enum).
Direction convertStringToEnumDir(string direction) {
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

SKILL convertStringToEnumSkill(string skill) {
    if (skill == "TYPING")
        return TYPING;
    else if (skill == "LOGIC")
        return LOGIC;
    else if (skill == "SPEECH")
        return SPEECH;
    else if (skill == "CREATIVITY")
        return CREATIVITY;
    else if (skill == "CRAFTSMANSHIP")
        return CRAFTSMANSHIP;
    else if (skill == "JAPANESE")
        return JAPANESE;
    else if (skill == "INTELLIGENCE")
        return INTELLIGENCE;
    else if (skill == "SPIRITUALITY")
        return SPIRITUALITY;

    return NONE;
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
    if (input->at(0) == "QUIT")
            exit(EXIT_SUCCESS);
    else
        Handler::handle(input);
}

// no "arguments": ouput game manual
// one "argument": outputs command manual
void MAN::handle(vector<string>* input) {
    if (input->at(0) == "GUIDE") {
        if (input->size() == 1) {
            cout << endl << MANUAL;
            /*cout << endl << "Manual:" << endl << "----------------------" << endl;
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
            }*/
                
        }
    }
    else
        Handler::handle(input);
}

/* ACTION COMMANDS: GO, TAKE, INVENTORY, USE */

// moves player, if possible, from current room to another room in the specified direction
void GO::handle(vector<string>* input) {
    Player* p = Player::getPlayer();
    if (input->at(0) == "GO") {
        if (input->size() != 2) 
            cout << endl << "Invalid input." << endl << endl; // + MANUAL["GO"];
        else {
            vector<string>::iterator it = find(DIR.begin(), DIR.end(), input->at(1));
            if (it == DIR.end())
                cout << endl << "Please enter a valid direction. Possible directions are: NORTH, SOUTH, EAST, WEST, UP, and DOWN." << endl << endl; // MANUAL["GO"];
            else {
                if (!p->getLocation()->deniedEntry(convertStringToEnumDir(input->at(1)))) {
                    if (!(p->move((convertStringToEnumDir(input->at(1))))))
                        cout << endl << "There's nothing in that direction." << endl << endl;
                    else {
                        if (p->getLocation()->isClassroom()) {
                            SKILL required = (SKILL)p->getLocation()->getRequiredSkill();
                            
                            if (p->getSkill(required) >= p->getLocation()->getLowReq()) {
                                cout << endl << PrintColor(p->getLocation()->getName(), B_CYAN) << ": " << p->getLocation()->getClass(p->getSkill((SKILL)(p->getLocation()->getRequiredSkill()))) << endl;
                                cout << p->getLocation()->getDescriptionSkillLevel(p->getSkill(required)) << endl << endl;
                            } else {
                                cout << endl << "The door is locked. You do not have the prerequisites for " << p->getLocation()->getClass(1) << "." << endl << endl;
                                p->move(p->getLocation()->oppositeDirection(convertStringToEnumDir(input->at(1))));
                            }
                        } else {
                            //cout << PrintColor(p->getLocation()->getName(), B_CYAN) << endl;
                            cout << endl << p->getLocation()->getDescription() << endl << endl;
                            if (p->getLocation()->getName() == "MBB215") {
                                p->completeClass("CHAPEL");
                            }
                        }
                    }
                } else {
                    cout << p->getLocation()->requiresItem(convertStringToEnumDir(input->at(1))) << endl;
                }
            }
        }
    }
    else
        Handler::handle(input);
}

// removes specified item from location and adds it to player's inventory
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
                    cout << "ITEM ADDED TO INVENTORY: " << item->getName() << endl;
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

void SKILLS::handle(vector<string>* input) {
    if (input->at(0) == "SKILLS") {
        if (input->size() != 1)
            cout << "Invalid input." << endl;
        else {
            cout << endl << "SKILLS:" << endl <<  "---------------------------------------------------------------------------------------------------------------------" << endl;
            for (unsigned int i = 0; i < STRING_SKILLS.size(); i++) {
                 cout.width(15); cout << std::left << STRING_SKILLS[i];
            }
            cout << endl;
            for (unsigned int i = 0; i < STRING_SKILLS.size(); i++) {
                cout.width(15); cout << std::left << Player::getPlayer()->getSkill(convertStringToEnumSkill(STRING_SKILLS[i]));
            }
            cout << endl<< "---------------------------------------------------------------------------------------------------------------------" << endl << endl;
        }
    }
    else
        Handler::handle(input);
}

void TALK::handle(vector<string>* input) {
    if (input->at(0) == "TALK" && input->size() == 1) {
        Player* player = Player::getPlayer();
        vector<Person*> people = player->getLocation()->getPeople();
        if (people.size() != 0) {
            int index = rand() % people.size();
            cout << endl << people.at(index)->getName() << ": " << people.at(index)->getDialogue() << endl << endl;
        }
        else
            cout << "There's no one to talk to." << endl;
    }
    else
        Handler::handle(input);
}

void LOOK::handle(vector<string>* input) {
    if (input->at(0) == "LOOK" && input->size() == 1) {
        Player* player = Player::getPlayer();
        if (player->getLocation()->isClassroom()) {
            cout << endl << PrintColor(player->getLocation()->getName(), B_CYAN) << ": " << player->getLocation()->getClass(player->getSkill((SKILL)(player->getLocation()->getRequiredSkill()))) << endl;
            cout << player->getLocation()->getDescriptionSkillLevel(player->getSkill((SKILL)(player->getLocation()->getRequiredSkill()))) << endl << endl;
        }
        else {
            cout << endl << player->getLocation()->getDescription() << endl << endl;
        }
    }
    else
        Handler::handle(input);
}

void DO::handle(vector<string>* input) {
    if (input->at(0) == "DO") {
        if (input->size() == 1) {
            cout << "What exactly do you want to DO?";
        }
        else if (input->size() == 2 && input->at(1) == "PROJECT") {
            Player* player = Player::getPlayer();
            player->getLocation()->doProject(player->getSkill((SKILL)(player->getLocation()->getRequiredSkill())));
        }
    }
    else
        Handler::handle(input);
}

/* DEBUG COMMANDS: INFO */

// output's current location, location inventory, and player inventory
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