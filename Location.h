#ifndef LOCATION_H
#define LOCATION_H

#include "GameObject.h"
#include "Person.h"
#include "Item.h"

#include <iostream>
#include <map>
#include <vector>
#include <string>
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
        int lowestReq;

        string askOutput;
        string completionOutput;
        vector<string> classNames;

      public:
        Location(string name = "", string desc = "", bool _isClassroom = false, int req = 0, vector<string> classes = {}, int lowReq = 0);

        Location* getLocation(Direction dir) const;

        void setDirection(Direction dir, Location* loc);
        bool checkDirection(Direction dir) const;
        void removeDirection(Direction dir);

        Direction oppositeDirection(Direction d) const;

        void addItem(Item* item);
        void removeItem(Item* item);

        void addPerson(Person* person);
        Person* removePerson(Person* person);

        vector<Item*>* getItems();

        string getDescription() const;
        void setDescription(string desc);

        string getDescription(string state) const;
        void setDescription(string state, string desc);

        // Adds a description to the location per skill level,
        // allowing multiple classes in one location
        void setDescriptionSkillLevel(int level, string desc);
        string getDescriptionSkillLevel(int level) const;

        // Checks if there is a description for that skill level
        bool hasDescriptionSkill(int level) const;

        // Origionally created to deny access to a room until you got an item,
        // now just denies access to the room and outputs the string
        void denyEntry(Direction dir, string item_required);
        void allowEntry(Direction dir);

        // Checks if the room is blocked, and outputs why
        bool deniedEntry(Direction dir) const;
        string requiresItem(Direction dir) const;

        void setClassroom(bool isClassroom) { classroom = isClassroom; }
        bool isClassroom() const { return classroom; }

        // Sets what skill the location is associated with
        void setRequiredSkill(int req) { required = req; }
        int getRequiredSkill() const { return required; }

        // What will be outputted when a project is completed in the room
        void setCompletionOutput(string output) { completionOutput = output; }
        string getCompletionOutput() const { return completionOutput; }

        // Returns the name of the class based on skill level
        string getClass(int i) const {return classNames.at(i);};

        void setAskOutput(string output) { askOutput = output; }
        string getAskOutput() const { return askOutput; }

        // Gets the lowest skill requirement value
        int getLowReq() const { return lowestReq; }

        vector<Person*> getPeople() const { return people; }

        // Function that changes the location when a project is completed
        void doProject(int skill);
};

#endif