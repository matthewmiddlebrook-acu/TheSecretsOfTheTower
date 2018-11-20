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
vector<string> STR_SKILLS = {"TYPING", "LOGIC", "SPEECH", "CREATIVITY", "CRAFTSMANSHIP", "JAPANESE", "INTELLIGENCE", "NONE"};

int main()
{
    /* INIT LOCATIONS */
    vector<string> noClasses = {""};
    vector<string> proClasses = {"PROGRAMMING 1", "PROGRAMMING 2"};
    vector<string> modClasses = {"INTRO TO 3D MODELING", "ADVANCED 3D MODELING"};
    vector<string> aniClasses = {"INTRO TO ANIMATION", "ADVANCED ANIMATION"};
    vector<string> busClasses = {"INTRO TO BUSINESS", "HOW TO FEEL GOOD WHILE GETTING A USELESS DEGREE"};

    Location MBB115("MBB115","PROGRAMMING Classroom", true, 1, proClasses);                                     // LOGIC
    Location MBB118("MBB118","BUSINESS Classroom", true, 2, busClasses);                                        // SPEECH
    Location MBBStairs1("MBBStairs1","You enter the stairwell.", false, 7, noClasses);
    Location MBBHallway1("MBBHallway1","You enter the hallway. There's classroom's on your WEST and EAST.\n" \
                         "Behind you (SOUTH), is the stairwell.\n", false, 7, noClasses);                       
    Location MBB215("MBB215","CHAPEL", false, 7, noClasses); 
    Location MBB218("MBB218","EMPTY CLASSROOM", false, 7, noClasses);
    Location MBBStairs2("MBBStairs2","You enter the stairwell.", false, 7, noClasses);
    Location MBBHallway2("MBBHallway2","You enter the hallway. There's classroom's on your WEST and EAST.\n" \
                         "Behind you (SOUTH), is the stairwell.\n", false, 7, noClasses);
    Location MBB315("MBB315","3D MODELING Classroom", true, 4, modClasses);                                     // CRAFTSMANSHIP
    Location MBB318("MBB318","ANIMATION Classroom", true, 3, aniClasses);                                       // CREATIVITY
    Location MBBStairs3("MBBStairs3","You enter the stairwell.",false, 7, noClasses);
    Location MBBHallway3("MBBHallway3","You enter the hallway. There's classroom's on your WEST and EAST.\n" \
                         "Behind you (SOUTH), is the stairwell.\n", false, 7, noClasses);
    
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

    vector<Location*> Locations;

    Locations.push_back(&MBB115);
    Locations.push_back(&MBB118);
    Locations.push_back(&MBBStairs1);
    Locations.push_back(&MBBHallway1);

    Locations.push_back(&MBB215);
    Locations.push_back(&MBB218);
    Locations.push_back(&MBBStairs2);
    Locations.push_back(&MBBHallway2);
    
    Locations.push_back(&MBB315);
    Locations.push_back(&MBB318);
    Locations.push_back(&MBBStairs3);
    Locations.push_back(&MBBHallway3);

   


    /* INIT ITEMS */
    string sched = 
        "SCHEDULE:\n" \
        "-----------------------------\n" \
        "Classes Being Offered:\n";
    



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

    /*for (unsigned int i = 0; i < Locations.size(); i++) {
        if (Locations.at(i)->isClassroom()) {
            sched += Locations.at(i)->getName() + "\t" + Locations.at(i)->getClass(player->getSkill((SKILL)Locations.at(i)->getRequiredSkill())) + "\n"; // need to add teacher
            //cout << Locations.at(i)->getName() << "\t" << Locations.at(i)->getClass(player->getSkill((SKILL)Locations.at(i)->getRequiredSkill())) << "\t" << STR_SKILLS.at(Locations.at(i)->getRequiredSkill()) << endl;
        }      
    }*/

    //cout << sched << endl;

    /* INIT GAME */
    //system("CLS");
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
            "What subject would you like to bring in credit for?\"";
    cout << endl << endl;
    cout << "TYPE ONE OF THE FOLLOWING: "; // only programming works right now
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
        else {
            cout << "Please enter a valid class." << endl << endl;
            cout << "TYPE ONE OF THE FOLLOWING: "; // only programming works right now
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

    MBB315.setDescriptionSkillLevel(1, 
        "You walk into 315 and are greeted by Professor Tanner, drinking a cup of coffee. He has a dazed, yet crazed look\n" \
        "in his eyes. He says, \"Welcome, " + player->getName() + ", to Into to 3D Modeling! Today, we are going to get\n" \
        "started on our first assignment where we will be learning Blender by modeling these donuts I have with me.\"\n" \
        "He holds up a plate of two donuts, covered in sprinkles and chocolate icing. They look absolutely delicious.\n"
        "\"This should be a fun assignment!\"");

    MBB315.setDescriptionSkillLevel(2, 
        "You walk into 315 again to take another class with Professor Tanner, and see him drinking from his green\n" \
        "Mario themed warp pipe mug, and what is probably his fifth cup of coffee...this morning. He shouts in a\n" \
        "terrible scottish accent, \"ALL RIGHT ME STUDENTS!\" The classroom grows quiet. \" Today, we are going to\n" \
        "do thegreatest assignment ever.\" He takes a sip from his coffee and stares at you. \"We are going to model\n" \
        "an Anvil.\" The class groans, remembering the horror stories of students who have formerly taken the class.\n" \
        "\"Oh stop it!\" Tanner exclaims. \"You can do it!\"");

    MBB318.setDescriptionSkillLevel(1,
        "Inside the classroom, you see a bunch of students with a half dead look on their faces, tired from waking\n" \
        "up for class at 8 am. Professor Tanner walks into the classroom, with a coffee mug in his hand. \"OY!!\"\n" \
        "he yells. \"For our first assignment, we are going to make a train animation! It's gonna be great! Hopefully...\"\n");


    MBB118.setDescriptionSkillLevel(1,
        "You walk into your Intro to Business class and see your generic professor, who greets you. \"Hello, student.\"\n" \
        "They didn't even call you by name.");

        MBB115.setDescriptionSkillLevel(1,
        "You walk into your Intro to Business class and see your generic professor, who greets you. \"Hello, student.\"\n" \
        "They didn't even call you by name.");

    

    cout << endl;

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

