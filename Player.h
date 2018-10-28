#include "person.h"
#include "location.h"

#include <iostream>
using namespace std;

class Player : Person {
    public:
        static Player* getPlayer();
        
        void move(Direction dir);
        void getItem(Item* pickup);
    private:
        static Player* p_instance;
        Player();

        Location* currentLocation;
        Location** visitedLocations;
}