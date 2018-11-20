#ifndef LOCATION_H
#define LOCATION_H

#include "GameObject.h"
#include "Person.h"
#include "Item.h"

#include <iostream>
#include <map>
#include <vector>
using namespace std;

// If you want to add more directions to the Direction enum, 
// keep NUM_DIRECTIONS at the end for correct total length
enum Direction{NORTH, SOUTH, EAST, WEST, UP, DOWN, NUM_DIRECTIONS};

class Location : public GameObject {
    private:
        Location* locations[NUM_DIRECTIONS];
        vector<Item*> items;
        vector<Person*> people;
        map<string, string> descriptions;
        map<Direction, string> denied;
        bool classroom = false;
        int required = 7;

        string askOutput;
        string completionOutput;

      public:
        Location(string name = "", string desc = "");

        Location* getLocation(Direction dir);
        //reEntry means it automatically connects the other location to this one 
        void setDirection(Direction dir, Location* loc);
        bool checkDirection(Direction dir);

        Direction oppositeDirection(Direction d);

        void addItem(Item* item);
        void removeItem(Item* item);

        void addPerson(Person* person);
        Person* removePerson(Person* person);

        vector<Item*>* getItems();

        string getDescription();
        void setDescription(string desc);

        string getDescription(string state);
        void setDescription(string state, string desc);

        // Attempted to add descriptions for skills, still not used yet though...
        void setDescriptionSkillLevel(int level, string desc);
        string getDescriptionSkillLevel(int level);

        bool hasDescriptionSkill(int level);

        void denyEntry(Direction dir, string item_required);
        void allowEntry(Direction dir);

        bool deniedEntry(Direction dir);
        string requiresItem(Direction dir);

        void setClassroom(bool isClassroom) { classroom = isClassroom; }
        bool isClassroom() { return classroom; }

        void setRequiredSkill(int req) { required = req; }
        int getRequiredSkill() { return required; }

        void setCompletionOutput(string output) { completionOutput = output; }
        string getCompletionOutput() { return completionOutput; }

        void setAskOutput(string output) { askOutput = output; }
        string getAskOutput() { return askOutput; }
};

#endif