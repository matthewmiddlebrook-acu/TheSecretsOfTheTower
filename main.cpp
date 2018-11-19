#include "GameObject.h"
#include "Location.h"
#include "Player.h"
#include "Command.h"
#include "PrintColor.h"

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

// still need cas to handle whitespace

vector<string> CLASSES {"PROGRAMMING", "SCRIPTING", "ANIMATION", "3D MODELING", "BUSINESS"};

int main()
{
    /* INIT LOCATIONS */
    Location Atrium("Atrium","");
    Location MBB115("MBB115","Scripting");
    Location MBB118("MBB118","Business");
    Location MBBHallway1("MBBHallway1","");
    Location MBBStairs1("MBBStairs1","");
    Location MBB215("MBB215","Programming");
    Location MBB218("MBB218","Chapel");
    Location MBBHallway2("MBBHallway2","");
    Location MBBStairs2("MBBStairs2","");
    Location MBB315("MBB315","3D Modeling");
    Location MBB318("MBB318","Animation");
    Location MBBHallway3("MBBHallway3","");
    Location MBBStairs3("MBBStairs3","");

    MBBHallway1.setDirection(EAST,&MBB115);
    MBBHallway1.setDirection(WEST,&MBB118);
    MBBHallway1.setDirection(SOUTH,&MBBStairs1);
    MBBStairs1.setDirection(UP,&MBBStairs2);
    MBBHallway2.setDirection(EAST,&MBB215);
    MBBHallway2.setDirection(WEST,&MBB218);
    MBBStairs2.setDirection(UP,&MBBStairs3);
    MBBStairs3.setDirection(NORTH,&MBBHallway3);
    MBBHallway3.setDirection(EAST,&MBB315);
    MBBHallway3.setDirection(WEST,&MBB318);

    /* INIT ITEMS */
    Item Schedule("Schedule","");
    Item GuideBook("GuideBook","");

    /* INIT HANDLERS */
    QUIT root;
    MAN  man;
    GO   go;
    TAKE take;
    INFO info;
    // LOOK  look;
    SKILLS skill;
    INVENTORY inv;

    root.add(&man);
    root.add(&go);
    root.add(&take);
    root.add(&info);
    root.add(&inv);
    root.add(&skill);

    /* INIT PLAYER */
    Player* player = Player::getPlayer();
    player->setLocation(&MBBHallway1);
    string name, course;


    /* INIT GAME */
    system("CLS");
    cout << "\"You\'re going to need to take varying classes to get into a graduate program and pass the GRE. Here in SITC\n" \
            "we offer courses in Scripting, Programming, Animation, 3D Modeling, and last, but definitely least, Business.\"";
    cout << endl << endl;
    cout << "A sweet, kindhearted woman sitting behind her desk is lecturing you about your class schedule. Great, my\n"   \
            "freshman year hasn\'t even begun and I\'m already getting lectured by... you glace at the lady\'s nametag...\n" \
            "MARY BETH CUEVAS. I guess she\'s just trying to help me out. I should probably pay attention.";
    cout << endl << endl;
    cout << "\"...avoid that class at all costs. Oh, and never take Homer. All the students say he\'s the worst. And well,\n" \
            "that\'s the rundown. What did you say your name was again honey?\"";
    cout << endl << endl;
    cout << "TYPE NAME HERE: ";
    getline(cin,name);
    player->setName(name);
    cout << endl;
    cout << "\"Well, " + player->getName() + ", here\'s your schedule of the classes you can take. Complete one class and you\'ll\n" \
            "be able to move onto the next one. Did you come in with any previous credit? If so, you can clep out of the\n" \
            "entry level course for one of the following: SCRIPTING, PROGRAMMING, ANIMATION, 3D MODELING, or BUSINESS.\n" \
            "Would you like to clep out?\"";
    cout << endl << endl;
    cout << "TYPE ONE OF THE FOLLOWING OR NONE: "; // only programming works right now
    getline(cin,course);
    transform(course.begin(), course.end(), course.begin(), ::toupper);
    while (true) {
        if (count(CLASSES.begin(), CLASSES.end(), course)) {
            cout << endl;
            cout << "You feel a surge of energy rush through your body. AHHHHHHHHHHH... ARRGGGGGHHHHHH. Power seeps into your skin.\n" \
                    "You take a deep breath. You feel stronger than before. Everything is clearer. You have cleped out of the intro\n" \
                    "course for " << course << ".";
            player->completeClass(course);
            break;
        }
        else if (course == "NONE") {
            cout << endl;
            break;
        }
        else {
            cout << "Please enter a valid class or fill in the option NONE." << endl << endl;
            cout << "TYPE ONE OF THE FOLLOWING OR NONE: "; // only programming works right now
            getline(cin,course);
            transform(course.begin(), course.end(), course.begin(), ::toupper);
        }
    }
    cout << "\"Now that that\'s out of the way, here\'s your schedule and your campus guide.\" Ms. Cuevas hands you two papers.\n";
    cout << endl;
    cout << "TWO ITEMS ADDED TO INVENTORY: SCHEDULE, GUIDEBOOK\n";
    cout << endl;
    player->addItem(&Schedule);
    player->addItem(&GuideBook);
    cout << "\"If you have any questions concerning how to navigate campus or classes, please feel free to look at your guidebook\n" \
            "by typing GUIDE. I wish you the best of luck with school tomorrow.\"";
    cout << endl << endl;
    cout << "You grab your belongings and exit the room. You remember Ms. Cuevas\' advice about avoiding Homer. School beings\n" \
            "tomorrow. Freshman year. College life. Tomorrow... Parties. Freedom. Friends. Tomorrow...";
    cout << endl << endl;
    cout << "THE NEXT DAY" << endl << endl;

    while (true)
    {
            string input;
            cout << "~ ";

            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(), ::toupper);
            vector<string> v;
            stringstream ss(input);

            for (string word; ss >> word;)
                v.push_back(word);
    
            root.handle(&v);
    }
}

