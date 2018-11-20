#include "Player.h"

#include <iostream>
using namespace std;

Player* Player::p_instance = 0;

Player* Player::getPlayer() {
    if (!p_instance)
        p_instance = new Player;
    return p_instance;
}

Location* Player::getLocation() const {
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

bool Player::completeClass(string course) {
    if (course == "PROGRAMMING") {
        increaseSkill(TYPING,1);
        increaseSkill(LOGIC,1);
        increaseSkill(INTELLIGENCE,1);
        cout << endl << endl;
        cout << "POWER UP : SKILLS ADVANCED" << endl;
        cout << "TYPING: " << getSkill(TYPING) << endl; 
        cout << "LOGIC: " << getSkill(LOGIC) << endl;
        cout << "INTELLIGENCE: " << getSkill(INTELLIGENCE) << endl;
        cout << endl;

        return true;
    }
    if (course == "SCRIPTING") {
        increaseSkill(TYPING,1);
        increaseSkill(LOGIC,1);
        increaseSkill(INTELLIGENCE,1);
        cout << endl << endl;
        cout << "POWER UP : SKILLS ADVANCED" << endl;
        cout << "TYPING: " << getSkill(TYPING) << endl; 
        cout << "LOGIC: " << getSkill(LOGIC) << endl;
        cout << "INTELLIGENCE: " << getSkill(INTELLIGENCE) << endl;
        cout << endl;

        return true;
    }
    if (course == "ANIMATION") {
        increaseSkill(JAPANESE,1);
        // increaseSkill(CRAFTSMANSHIP,1);
        increaseSkill(CREATIVITY,1);
        increaseSkill(INTELLIGENCE,1);
        cout << endl << endl;
        cout << "POWER UP : SKILLS ADVANCED" << endl;
        cout << "JAPANESE: " << getSkill(JAPANESE) << endl; 
        // cout << "CRAFTSMANSHIP: " << getSkill(CRAFTSMANSHIP) << endl;
        cout << "CREATIVITY: " << getSkill(CREATIVITY) << endl;
        cout << "INTELLIGENCE: " << getSkill(INTELLIGENCE) << endl;
        cout << endl;

        return true;
    }
    if (course == "3D MODELING") {
        increaseSkill(CRAFTSMANSHIP,1);
        // increaseSkill(CREATIVITY,1);
        increaseSkill(INTELLIGENCE,1);
        cout << endl << endl;
        cout << "POWER UP : SKILLS ADVANCED" << endl;
        cout << "CRAFTSMANSHIP: " << getSkill(CRAFTSMANSHIP) << endl;
        // cout << "CREATIVITY: " << getSkill(CREATIVITY) << endl;
        cout << "INTELLIGENCE: " << getSkill(INTELLIGENCE) << endl;
        cout << endl;

        return true;
    }
    if (course == "BUSINESS") {
        increaseSkill(SPEECH,1);
        decreaseSkill(INTELLIGENCE,1);
        cout << endl << endl;
        cout << "POWER SHIFT : SKILLS CHANGED" << endl;
        cout << "SPEECH: " << getSkill(SPEECH) << endl;
        cout << "INTELLIGENCE: " << getSkill(INTELLIGENCE) << endl;
        cout << endl;

        return true;
    }
    if (course == "ITC110") {
        increaseSkill(LOGIC,1);
        increaseSkill(TYPING,1);
        increaseSkill(JAPANESE,1);
        increaseSkill(SPEECH,1);
        increaseSkill(CRAFTSMANSHIP,1);
        increaseSkill(CREATIVITY,1);
        increaseSkill(INTELLIGENCE,1);
        cout << endl << endl;
        cout << "POWER UP : SKILLS ADVANCED" << endl;
        cout << "TYPING: " << getSkill(TYPING) << endl;
        cout << "LOGIC: " << getSkill(LOGIC) << endl;
        cout << "SPPECH: " << getSkill(SPEECH) << endl;
        cout << "CRAFTSMANSHIP: " << getSkill(CRAFTSMANSHIP) << endl;
        cout << "CREATIVITY: " << getSkill(CREATIVITY) << endl;
        cout << "INTELLIGENCE: " << getSkill(INTELLIGENCE) << endl;
        cout << endl;
    }
    return false;

}