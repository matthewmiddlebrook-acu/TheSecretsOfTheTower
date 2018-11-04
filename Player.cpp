#include "Player.h"

#include <iostream>
using namespace std;

Player* Player::p_instance = 0;

Player* Player::getPlayer() {
    if (!p_instance)
        p_instance = new Player;
    return p_instance;
}

Location* Player::getLocation() {
    return currentLocation;
}

void Player::setLocation(Location* location) {
    currentLocation = location;
    visitedLocations.insert(location);
}

bool Player::move(Direction dir) {
    if (currentLocation->checkDirection(dir)) {
        setLocation(currentLocation->getLocation(dir));
        return true;
    } else {
        return false;
    }
}