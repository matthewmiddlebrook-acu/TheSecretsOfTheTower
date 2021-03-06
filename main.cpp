#include "GameObject.h"
#include "Location.h"
#include "Player.h"
#include "Command.h"
#include "PrintColor.h"

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <windows.h>
using namespace std;

// still need cas to handle whitespace

vector<string> CLASSES {"PROGRAMMING", "SCRIPTING", "ANIMATION", "3D MODELING", "BUSINESS"};
vector<string> STR_SKILLS = {"TYPING", "LOGIC", "SPEECH", "CREATIVITY", "CRAFTSMANSHIP", "JAPANESE", "INTELLIGENCE", "NONE", "GENERAL", "SPIRITUALITY"};

bool finished(vector<Location*> Loc) {
    int count = 0;
    for (unsigned int i = 0; i < Loc.size(); i++)
        if (Loc.at(i)->isClassroom() && Player::getPlayer()->getSkill((SKILL)(Loc.at(i)->getRequiredSkill())) >= Loc.at(i)->getLowReq())
            count++;
    return count == 0;
}

void schedule(vector<Location*> Loc) {
    string sched =
            "\nSCHEDULE:\n" \
            "-----------------------------\n" \
            "Classes Being Offered:\n";
    for (unsigned int i = 0; i < Loc.size(); i++)
        if (Loc.at(i)->isClassroom() && Player::getPlayer()->getSkill((SKILL)(Loc.at(i)->getRequiredSkill())) >= Loc.at(i)->getLowReq()) {
            // cout << endl << Loc.at(i)->getPeople().at(0)->getName() <<endl;

            sched += Loc.at(i)->getName() + "\t" + Loc.at(i)->getClass(Player::getPlayer()->getSkill((SKILL)Loc.at(i)->getRequiredSkill())) + "\n";
            //  + "\t" + Loc.at(i)->getPeople().at(0)->getName() + "\n"; 
            
        }
           
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
    TALK tlk;
    DO doh;
    LOOK lok;

    root.add(&man);
    root.add(&go);
    root.add(&take);
    root.add(&info);
    root.add(&inv);
    root.add(&skill);
    root.add(&tlk);
    root.add(&doh);
    root.add(&lok);

    // INIT LOCATIONS //
    string course;

    vector<string> noClasses = {""};
    vector<string> itcClasses = {"INTRO TO ITC"};
    vector<string> proClasses = {"","PROGRAMMING 1", "PROGRAMMING 2"};
    vector<string> modClasses = {"","INTRO TO 3D MODELING", "ADVANCED 3D MODELING"};
    vector<string> aniClasses = {"","INTRO TO ANIMATION", "ADVANCED ANIMATION"};
    vector<string> busClasses = {"","INTRO TO BUSINESS", "\"ADVANCED\" BUSINESS"};

    Location MBB115("MBB115","PROGRAMMING Classroom", true, 1, proClasses, 1);                                     // LOGIC
    Location MBB118("MBB118","BUSINESS Classroom", true, 2, busClasses, 1);                                        // SPEECH
    Location MBBStairs1("MBBStairs1","You're in the first floor stairwell.", false, 7, noClasses, 0);
    Location MBBHallway1("MBBHallway1","You're in the first floor the hallway. There's classrooms to your WEST and EAST.\n" \
                         "Behind you (SOUTH), is the stairwell.", false, 7, noClasses, 0);                       
    Location MBB215("MBB215","CHAPEL: Dr. Homer and Dr. Prather are in here with wisdom to share.", false, 7, noClasses, 0); 
    Location MBB218("MBB218","ANIMATION Classroom", true, 3, aniClasses, 1);
    Location MBBStairs2("MBBStairs2","You're in the second floor stairwell.", false, 7, noClasses, 1);
    Location MBBHallway2("MBBHallway2","You're in the second floor hallway. There's classrooms to your WEST and EAST.\n" \
                         "Behind you (SOUTH), is the stairwell.", false, 7, noClasses,0);
    Location MBB315("MBB315","3D MODELING Classroom", true, 4, modClasses, 1);                                     // CRAFTSMANSHIP
    Location MBB318("MBB318","ITC 110 Classroom", true, 8, itcClasses, 0);                                         // CREATIVITY
    Location MBBStairs3("MBBStairs3","You're in the third floor stairwell.",false, 7, noClasses, 0);
    Location MBBHallway3("MBBHallway3","You're in the third floor hallway. There's classrooms to your WEST and EAST.\n" \
                         "Behind you (SOUTH), is the stairwell.", false, 7, noClasses, 0);
    
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

    // Programming
    MBB115.setDescriptionSkillLevel(1, 
        "You see Dr. Prather sitting patiently in a chair at the front of the classroom. As all the students file in,\n" \
        "he announces the project for the course. \"You are going to be giving a sacrifice to the all powerful Athene!\n" \
        "Please! Prepare your sacrifice quickly! You don't want to make her angry!");

    MBB115.setDescriptionSkillLevel(2, 
        "As you enter the classroom, there is a faint smell of data structures. As you sit down, you notice that Dr. Prather\n" \
        "is staring right at you. He shouts, \"Athene demands another sacrifice! Get it done quickly!\"");

    MBB115.setCompletionOutput(
        "Athene: Assignment passed all test cases. You will live another day.");


    // 3D Modeling
    MBB315.setDescriptionSkillLevel(1, 
        "You walk into the room and are greeted by Professor Tanner, drinking a cup of coffee. He has a dazed, yet crazed look\n" \
        "in his eyes. He says, \"Welcome, " + player->getName() + ", to Into to 3D Modeling! Today, we are going to get\n" \
        "started on our first assignment where we will be learning Blender by modeling these donuts I have with me.\"\n" \
        "He holds up a plate of two donuts, covered in sprinkles and chocolate icing. They look absolutely delicious.\n"
        "\"This should be a fun assignment!\"");

    MBB315.setDescriptionSkillLevel(2, 
        "You walk into the room again to take another class with Professor Tanner, and see him drinking from his green\n" \
        "Mario themed warp pipe mug, and what is probably his fifth cup of coffee...this morning. He shouts in a\n" \
        "terrible scottish accent, \"ALL RIGHT ME STUDENTS!\" The classroom grows quiet. \" Today, we are going to\n" \
        "do the greatest assignment ever.\" He takes a sip from his coffee and stares at you. Time seems to stand still.\n" \
        "\"We are going to model an Anvil.\" The class groans, remembering the horror stories of students who have\n" \
        "formerly taken the class. \"Oh stop it!\" Tanner exclaims. \"You can do it!\"");

    MBB315.setCompletionOutput(
        "\"Great job!\" Professor Tanner tells you. \"You completed a beautiful render!\"");


    // Animation
    MBB218.setDescriptionSkillLevel(1,
        "Inside the classroom, you see a bunch of students with a half dead look on their faces, tired from waking\n" \
        "up for class at 8 am. Professor Tanner walks into the classroom, with a coffee mug in his hand. \"OY!!\"\n" \
        "he yells. \"For our first assignment, we are going to make a train animation! It's gonna be great! Hopefully...\"");
    
    MBB218.setDescriptionSkillLevel(2,
        "You walk inside the Animation classroom, but there's no one inside. You wait a bit, and students finally\n" \
        "start showing up. Class is supposed to be starting soon, but the professor isn't even here yet.\n" \
        "Right at class time, Professor Tanner finally walks in, with a wooden figurine. \"Morning class, today we are\n" \
        "going to be creating a running animation. I've brought this guy here for reference. Good luck!\"");

    MBB218.setCompletionOutput(
        "\"Wow!\" Professor Tanner tells you. \"It looks so realistic! I'm really impressed with your ASCII art skills!\n" \
        "How long did it take you to do that though???\" ... Did Professor Tanner just break the 4th wall? Did I???");


    // ITC 110
    MBB318.setDescriptionSkillLevel(0,
        "In the large classroom, you see Dr. Burton standing in the front excitedly moving his hands, talking about\n" \
        "the latest and greatest thing in the technology entertainment industry. Around the classroom, you see many other\n" \
        "students, eager to work on their first group project that requires them to program before they learn how.");

    MBB318.setCompletionOutput(
        "\"Wow!\" Dr. Burton exclaims. \"This is one of the best projects that I've ever seen. Great job!\"");
    

    // Business
    MBB118.setDescriptionSkillLevel(1,
        "You walk into your Intro to Business class and see your generic professor, who greets you. \"Hello, student.\"\n" \
        "They didn't even call you by name.");
    
    MBB118.setDescriptionSkillLevel(2,
        "You walk into your Business class and see your generic professor, who greets you. \"Hello, student.\"\n" \
        "They \"put a face to my name,\" yet they still failed to mention my name. Why am I going to this class?");
    
    MBB118.setCompletionOutput(
        "\"Great.\" The professor says, extreeemely enthusiastically. \"Good luck having a successful business though.\n" \
        "Look where I am. Of all the things I could have done in my life, I teach business.\" Yikes. They seem to be\n" \
        "having an existential crisis. Oh well. You did...something.");

    // INIT GAME //
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
    cout << "\"Well, " + player->getName() + ", now that that\'s out of the way, here\'s your schedule and your campus guide.\" Ms. Cuevas hands you two papers.\n";
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
    player->setLocation(&MBBHallway1);
    cout << "Your standing in the first floor hallway of the Mabee Business Building. Schedule in hand, you\'re ready to\n" \
            "start your college experience...";
    cout << endl << endl;

    // Create a handler TALK, returns random string of person, size of vector

    Person burton = Person("Dr. Burton");
    burton.setDialogue("\"Buy my book! I've written many books on Corona and Amazon Lumberyard.\"");
    burton.setDialogue("\"Man buns are cool.\"");
    burton.setDialogue("\"Did you hear about the new [generic tech] yet? It sounds amazing!\"");
    burton.setDialogue("\"There's no cheating in DET.\"");
    burton.setDialogue("\"Hi.\"");

    Person prather = Person("Dr. Prather");
    prather.setDialogue("\"HCI is the greatest thing on the face of the earth.\"");
    prather.setDialogue("\"You should totally join HCI club! We're gonna present our research at SIGCHI!\"");
    prather.setDialogue("\"I encountered a badly designed door the other day. It was awful\"");
    prather.setDialogue("\"Have you seen any Norman doors lately? Ya know, the ones you think before opening?\"");
    prather.setDialogue("\"That's the best designed door I've ever seen.\"");

    Person tanner = Person("Professor Tanner");
    tanner.setDialogue("\"Do all the things.\"");
    tanner.setDialogue("\"Don't you have an assignment to complete?\"");
    tanner.setDialogue("\"Where did I leave my coffee?\"");
    tanner.setDialogue("\"Can you go get me Taco Bell?\"");
    tanner.setDialogue("\"Man I am really craving a taco right now.\"");

    Person bProf = Person("Business Professor");
    bProf.setDialogue("\"It's good to put a face to the name.\"");
    bProf.setDialogue("\"You need to wrap your head around this assignment.\"");
    bProf.setDialogue("\"You need to think outside the box.\"");
    bProf.setDialogue("\"Who's going to step up to the plate?\"");
    bProf.setDialogue("\"My students know I've got an open door policy.\"");
    bProf.setDialogue("\"I definitely do not just say business cliches.\"");


    Person wiseHomer = Person("Dr. Homer");
    wiseHomer.setDialogue("\"HTML is a Programming Language\"\n-Dr. Pettit");
    wiseHomer.setDialogue("\"Ruin and misery are in their paths.\"\n-Romans 3:16");
    wiseHomer.setDialogue("\"I pray that, according to the riches of his glory, he may grant that you\nmay be strengthened in your inner being with power through his Spirit.\"\n-Ephesians 3:16");
    wiseHomer.setDialogue("\"He has made my teeth grind on gravel,\nand made me cower in ashes;\"\n-Lamentations 3:16");
    wiseHomer.setDialogue("\"I put a lot of effort into that PowerPoint presentation. Weren't the animations great?\"");

    Person wisePrather = Person("Dr. Prather");
    wisePrather.setDialogue("\"Ehud made for himself a sword with two edges, a cubit in length;\nand he fastened it on his right thigh under his clothes.\n-Judges 3:16\"");
    wisePrather.setDialogue("\"Let the word of Christ dwell in you richly; teach and admonish one another in all wisdom;\nand with gratitude in your hearts sing psalms, hymns, and spiritual songs to God.\"\n-Colossians 3:16");
    wisePrather.setDialogue("\"Do you not know that you are God's temple and that God's Spirit dwells in you?\"\n-1 Corinthians 3:16");
    wisePrather.setDialogue("\"Long life is in her right hand;\nin her left hand are riches and honour.\"\n-Proverbs 3:16");
    wisePrather.setDialogue("\"The Lord roars from Zion,\nand utters his voice from Jerusalem,\nand the heavens and the earth shake.\nBut the Lord is a refuge for his people,\na stronghold for the people of Israel.\"\n-Joel 3:16");

    MBB215.addPerson(&wiseHomer);
    MBB215.addPerson(&wisePrather);


    MBB318.addPerson(&burton);

    MBB218.addPerson(&tanner);
    MBB315.addPerson(&tanner);

    MBB115.addPerson(&prather);
    MBB118.addPerson(&bProf);

    // "The final exam is now available. At anytime you are ready, type ___ to take the final."
    // "Are you ready to take the final?";
    // "What is your favorite color?";

    // CREATE GUIDEBOOK //

    cout << endl;

    while (true)
    {
        if (finished(Locations)) {
            cout << endl;
            Sleep(500);
            cout << "You have completed all of the classes in the SITC department. You are now ready to complete the final exam." << endl;
            cout << "Be warned, this is a very hard exam. The exam will now commence." << endl;
            Sleep(2000);
            cout << endl;
            cout << "Who approaches the Bridge of Death" << endl;
            Sleep(500);
            cout << "Must answer me" << endl;
            Sleep(500);
            cout << "These questions three!"<< endl;
            Sleep(500);
            cout << "Ere the other side he see." << endl;
                Sleep(2000);
            cout << endl;
            cout << "Whaaaaaat is your name?: My name is...";
            string name_quiz;
            getline(cin, name_quiz);
            cout << endl;
            Sleep(1000);
            cout << endl;
            cout << "Whaaaaaat is your quest?: To find the...";
            string quest_quiz;
            getline(cin, quest_quiz);
            cout << endl;
            Sleep(1000);
            cout << endl;
            cout << "Whaaaaaat is your favorite color?: ";
            string color_quiz;
            getline(cin, color_quiz);
            cout << endl;
            Sleep(5000);
            transform(name_quiz.begin(), name_quiz.end(), name_quiz.begin(), ::toupper);
            transform(name.begin(), name.end(), name.begin(), ::toupper);
            transform(quest_quiz.begin(), quest_quiz.end(), quest_quiz.begin(), ::toupper);
            transform(color_quiz.begin(), color_quiz.end(), color_quiz.begin(), ::toupper);
            if (name_quiz == name && quest_quiz == "HOLY GRAIL" && color_quiz == "BLUE") {
                cout << "Right. Off you go." << endl;
                Sleep(1000);
                cout << "Congratulations, you have passed the final exam!" << endl;
                Sleep(1000);
                cout << endl;
                cout << "Thank you for taking classes at SITC. Now that you have graduated,\n" \
                    "may you take the knowledge you have learned and make a successful living.\n" \
                    "Thanks for your $46,000 a year! We hope to receive donations from you soon.\n" \
                    "Just remember: when you donate, we put all the money on football stadiums." << endl;
            } else {
                cout << "College is a place where you build bridges." << endl;
                Sleep(1000);
                cout << "Since you incorrectly answered these questions," << endl;
                Sleep(500);
                cout << "you have fallen off your bridge and have lost your chance to graduate from SITC." << endl;
                Sleep(500);
                cout << "Please re-enroll to try again." << endl;
                Sleep(500);
                cout << "The game will now exit." << endl;
                Sleep(1000);
                return 0;
            }
            Sleep(1000);
            cout << endl;
            cout << "Press any key to quit." << endl;
            cin.ignore();
            return 0;
        } else {
            string input;
            cout << "~ ";

            getline(cin, input);
            transform(input.begin(), input.end(), input.begin(), ::toupper);
            vector<string> v;
            stringstream ss(input);
            for (string word; ss >> word;)
                v.push_back(word);

            if (v.size() == 0 )
                cout << endl << "Please enter a valid command." << endl << endl;
            else if (v.at(0) == "SCHEDULE" && v.size() == 1)
                schedule(Locations);
            else
                root.handle(&v);
        }
    }
}

