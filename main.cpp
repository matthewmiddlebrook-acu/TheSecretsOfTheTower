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
vector<string> STR_SKILLS = {"TYPING", "LOGIC", "SPEECH", "CREATIVITY", "CRAFTSMANSHIP", "JAPANESE", "INTELLIGENCE","NONE","GENERAL",};

void schedule(vector<Location*> Loc) {
    string sched =
            "SCHEDULE:\n" \
            "-----------------------------\n" \
            "Classes Being Offered:\n";
        for (unsigned int i = 0; i < Loc.size(); i++) 
            if (Loc.at(i)->isClassroom() && Player::getPlayer()->getSkill((SKILL)(Loc.at(i)->getRequiredSkill())) >= Loc.at(i)->getLowReq()) {
                sched += Loc.at(i)->getName() + "\t" + Loc.at(i)->getClass(Player::getPlayer()->getSkill((SKILL)Loc.at(i)->getRequiredSkill())) + "\n"; // need to add teacher
        cout << sched << endl;
}
        

int main()
{
    // INIT PLAYER //
    Player* player = Player::getPlayer();
    string name;

    // INIT ITEMS //
    Item Schedule("Schedule","");
    Item GuideBook("GuideBook","");

    // INIT HANDLERS //
    QUIT root;
    MAN  man;
    GO   go;
    TAKE take;
    INFO info;
    SKILLS skill;
    INVENTORY inv;

    root.add(&man);
    root.add(&go);
    root.add(&take);
    root.add(&info);
    root.add(&inv);
    root.add(&skill);

    // INIT LOCATIONS //
    string course;

    vector<string> noClasses = {""};
    vector<string> itcClasses = {"INTRO TO ITC"};
    vector<string> proClasses = {"PROGRAMMING 1", "PROGRAMMING 2"};
    vector<string> modClasses = {"INTRO TO 3D MODELING", "ADVANCED 3D MODELING"};
    vector<string> aniClasses = {"INTRO TO ANIMATION", "ADVANCED ANIMATION"};
    vector<string> busClasses = {"INTRO TO BUSINESS", "USELESS CLASS"};

    Location MBB115("MBB115","PROGRAMMING Classroom", true, 1, proClasses, 1);                                     // LOGIC
    Location MBB118("MBB118","BUSINESS Classroom", true, 2, busClasses, 1);                                        // SPEECH
    Location MBBStairs1("MBBStairs1","You enter the stairwell.", false, 7, noClasses, 0);
    Location MBBHallway1("MBBHallway1","You enter the hallway. There's classroom's on your WEST and EAST.\n" \
                         "Behind you (SOUTH), is the stairwell.\n", false, 7, noClasses, 0);                       
    Location MBB215("MBB215","CHAPEL", false, 7, noClasses, 0); 
    Location MBB218("MBB218","ANIMATION Classroom", true, 3, aniClasses, 1);
    Location MBBStairs2("MBBStairs2","You enter the stairwell.", false, 7, noClasses, 1);
    Location MBBHallway2("MBBHallway2","You enter the hallway. There's classroom's on your WEST and EAST.\n" \
                         "Behind you (SOUTH), is the stairwell.\n", false, 7, noClasses,0);
    Location MBB315("MBB315","3D MODELING Classroom", true, 4, modClasses, 1);                                     // CRAFTSMANSHIP
    Location MBB318("MBB318","ITC 110 Classroom", true, 8, itcClasses, 0);                                         // CREATIVITY
    Location MBBStairs3("MBBStairs3","You enter the stairwell.",false, 7, noClasses, 0);
    Location MBBHallway3("MBBHallway3","You enter the hallway. There's classroom's on your WEST and EAST.\n" \
                         "Behind you (SOUTH), is the stairwell.\n", false, 7, noClasses, 0);
    
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


    MBB318.setDescriptionSkillLevel(0, // itc 110
        "Inside the classroom, you see a bunch of students with a half dead look on their faces, tired from waking\n" \
        "up for class at 8 am. Professor Tanner walks into the classroom, with a coffee mug in his hand. \"OY!!\"\n" \
        "he yells. \"For our first assignment, we are going to make a train animation! It's gonna be great! Hopefully...\"\n");

    MBB318.setCompletionOutput( // itc 110
        "\"Wow!\" Professor Tanner tells you. \"It looks so realistic! I'm really impressed with your ASCII art skills!\n" \
        "How long did it take you to do that though???\"");


    MBB118.setDescriptionSkillLevel(1, // bus
        "You walk into your Intro to Business class and see your generic professor, who greets you. \"Hello, student.\"\n" \
        "They didn't even call you by name.");
    
    MBB118.setCompletionOutput( // bus
        "\"Great.\" The professor says, extreeemely enthusiastically. \"Good luck having a successful business though.\n" \
        "Look where I am. Of all the things I could have done in my life, I teach business.\" Yikes. They seem to be\n" \
        "having an existential crisis. Oh well. You did...something.");



    // INIT GAME //
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
    /*cout << "\"Well, " + player->getName() + ", here\'s your schedule of the classes you can take. Complete one class and you\'ll\n" \
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
            cout << "TYPE ONE OF THE FOLLOWING: ";
            getline(cin,course);
            transform(course.begin(), course.end(), course.begin(), ::toupper);
        }
    }*/
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

    // Create a handler TALK, returns random string of person, size of vector

    /*Person burton = Person("Dr. Burton");
    burton.setDialogue(0, "\"Buy my book! I've written many books on Corona and Amazon Lumberyard.\"");
    burton.setDialogue(1, "\"Man buns are cool.\"");
    burton.setDialogue(2, "\"Did you hear about the new [generic tech] yet? It sounds amazing!\"");
    burton.setDialogue(3, "\"There's no cheating in DET.\"");
    burton.setDialogue(4, "\"Hi.\"");

    // Don't know if I am going to use him, currently Tanner has 2 classes
    Person homer = Person("Dr. Homer");
    homer.setDialogue(0, "\"I actually don't like computers.\"");
    homer.setDialogue(1, "\"What are you kids on nowdays? MyChat? SnapFace?\"");
    homer.setDialogue(2, "\"I don't know why people are so scared of me. My children LOVE me.\" he says, while laughing.\nThen, he stares into your soul.");
    homer.setDialogue(3, "\"What was it that you wanted?\"");
    homer.setDialogue(4, "\"I put a lot of effort into that PowerPoint presentation. Weren't the animations great?\"");

    Person prather = Person("Dr. Prather");
    prather.setDialogue(0, "\"HCI is the greatest thing on the face of the earth.\"");
    prather.setDialogue(1, "\"You should totally join HCI club! We're gonna present our research at SIGCHI!\"");
    prather.setDialogue(2, "\"I encountered a badly designed door the other day. It was awful\"");
    prather.setDialogue(3, "\"Have you seen any Norman doors lately? Ya know, the ones you think before opening?\"");
    prather.setDialogue(4, "\"That's the best designed door I've ever seen.\"");

    Person tanner = Person("Professor Tanner");
    tanner.setDialogue(0, "\"Do all the things.\"");
    tanner.setDialogue(1, "\"Don't you have an assignment to complete?\"");
    tanner.setDialogue(2, "\"Where did I leave my coffee?\"");
    tanner.setDialogue(3, "\"Can you go get me Taco Bell?\"");
    tanner.setDialogue(4, "\"Man I am really craving a taco right now.\"");

    Person bProf = Person("Business Professor");
    bProf.setDialogue(0, "\"It's good to put a face to the name.\"");
    bProf.setDialogue(1, "\"You need to wrap your head around this assignment.\"");
    bProf.setDialogue(2, "\"You need to think outside the box.\"");
    bProf.setDialogue(3, "\"Who's going to step up to the plate?\"");
    bProf.setDialogue(4, "\"My students know I've got an open door policy.\"");
    bProf.setDialogue(5, "\"I definitely do not just say business cliches.\"");

    MBB318.addPerson(&tanner); //Change to 218 after merge
    MBB315.addPerson(&tanner);

    MBB115.addPerson(&prather);
    MBB118.addPerson(&bProf);*/

    // SET PLAYER //
    player->setLocation(&MBBHallway1);


    // CREATE GUIDEBOOK //

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

            if (v.at(0) == "SCHEDULE" && v.size() == 1)
                schedule(Locations);
            else
                root.handle(&v);
        }
    }
}

