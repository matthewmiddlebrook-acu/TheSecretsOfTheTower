#ifndef PLAYER_H
#define PLAYER_H

#include "Person.h"
#include "Location.h"

#include <set>
#include <map>
#include <iostream>
using namespace std;

enum SKILL{TYPING, LOGIC, SPEECH, CREATIVITY, CRAFTSMANSHIP, JAPANESE, INTELLIGENCE, NONE, GENERAL};


class Player : public Person {
    private:
        Location* currentLocation;
        set<Location*> visitedLocations;

        static Player* p_instance;
        Player(string name = "", string desc = "") : Person(name, desc) {}

        int skills[9] { };

      public:
        static Player* getPlayer();
        
        bool move(Direction dir);
        
        //void addItem(Item* pickup);
        void useItem();

        Location* getLocation();
        void setLocation(Location *location);

        bool completeClass(std::string course);
        void increaseSkill(SKILL s, int amount) { skills[s] += amount; }
        void decreaseSkill(SKILL s, int amount) { skills[s] -= amount; }
        int getSkill(SKILL s) { return skills[s]; }
};

#endif