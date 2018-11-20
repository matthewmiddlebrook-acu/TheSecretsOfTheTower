#include "GameObject.h"
#include "Location.h"
#include "Player.h"
#include "Command.h"
#include "PrintColor.h"
#include "ASCII.h"

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
    MBBHallway2.setDirection(SOUTH,&MBBStairs2);
    MBBStairs2.setDirection(UP,&MBBStairs3);
    MBBHallway3.setDirection(EAST,&MBB315);
    MBBHallway3.setDirection(WEST,&MBB318);
    MBBHallway3.setDirection(SOUTH,&MBBStairs3);

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

    MBB315.setClassroom(true);
    MBB315.setRequiredSkill(CRAFTSMANSHIP);
    
    MBB318.setClassroom(true);
    MBB318.setRequiredSkill(CREATIVITY);

    MBB315.setDescriptionSkillLevel(1, 
        "You walk into 315 and are greeted by Professor Tanner, drinking a cup of coffee. He has a dazed, yet crazed look\n" \
        "in his eyes. He says, \"Welcome, " + player->getName() + ", to Into to 3D Modeling! Today, we are going to get\n" \
        "started on our first assignment where we will be learning Blender by modeling these donuts I have with me.\"\n" \
        "He holds up a plate of two donuts, covered in sprinkles and chocolate icing. They look absolutely delicious.\n"
        "\"This should be a fun assignment!\"");

    MBB315.setCompletionOutput(
        "\"Great job!\" Professor Tanner tells you. \"You completed a beautiful render!\"");

    MBB315.setDescriptionSkillLevel(2, 
        "You walk into 315 again to take another class with Professor Tanner, and see him drinking from his green\n" \
        "Mario themed warp pipe mug, and what is probably his fifth cup of coffee...this morning. He shouts in a\n" \
        "terrible scottish accent, \"ALL RIGHT ME STUDENTS!\" The classroom grows quiet. \" Today, we are going to\n" \
        "do the greatest assignment ever.\" He takes a sip from his coffee and stares at you. Time seems to stand still.\n" \
        "\"We are going to model an Anvil.\" The class groans, remembering the horror stories of students who have\n" \
        "formerly taken the class. \"Oh stop it!\" Tanner exclaims. \"You can do it!\"");


    MBB318.setDescriptionSkillLevel(1,
        "Inside the classroom, you see a bunch of students with a half dead look on their faces, tired from waking\n" \
        "up for class at 8 am. Professor Tanner walks into the classroom, with a coffee mug in his hand. \"OY!!\"\n" \
        "he yells. \"For our first assignment, we are going to make a train animation! It's gonna be great! Hopefully...\"\n");

    MBB318.setCompletionOutput(
        "\"Wow!\" Professor Tanner tells you. \"It looks so realistic! I'm really impressed with your ASCII art skills!\n" \
        "How long did it take you to do that though???\"");


    MBB118.setDescriptionSkillLevel(1,
        "You walk into your Intro to Business class and see your generic professor, who greets you. \"Hello, student.\"\n" \
        "They didn't even call you by name.");
    
    MBB118.setCompletionOutput(
        "\"Great.\" The professor says, extreeemely enthusiastically. \"Good luck having a successful business though.\n" \
        "Look where I am. Of all the things I could have done in my life, I teach business.\" Yikes. They seem to be\n" \
        "having an existential crisis. Oh well. You did...something.");

    cout << endl;

    while (true)
    {
        string input;
        cout << "~ ";

        getline(cin, input);
        if (input != "" && input.find_first_not_of(' ') != std::string::npos) {
            transform(input.begin(), input.end(), input.begin(), ::toupper);
            vector<string> v;
            stringstream ss(input);

            for (string word; ss >> word;)
                v.push_back(word);

            root.handle(&v);
        }
    }
}

