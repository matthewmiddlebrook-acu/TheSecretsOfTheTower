#include <windows.h>
#include <sstream>
#include <iostream>
using namespace std;

// https://www.text-image.com/convert/ascii.html
// Use width of 120
// Image size 960x480

void donut() {
    cout <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyooo++/ooyyyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyo//--`.-/.-`.:-:++/+shmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmy+---:.-..`..`.-..::://:++//dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmmmmdds--....`--..:```...`..:o-:-/s+soymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmdyo-..-.-..+.`-..````.`-..-+:+:/+yssoyymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmy/-.`..-+::-:-.......-.`-..--:/::s/yyysyydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmd/-.---:/:sooo://+/::://:.`.-/:/+o/ss+o+sssoymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmms---::/:o+/ysyyyoyysssoo+-.-/:://oyyooyssssoshmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmd/`-.`..+yy+osyyyyyyyso+:...//:::/+oooss+osossodyhhdhhdddddhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmo`.--``..ososhyhhhsso++:-..:--:/:///+:++osssyoo/+:oo-+//--://:.:+oyyshdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmms .`--./::++ssydhy:/:---`/-.---/oo+//hysssyyss+:oddhsyyyyso++/+-:o+::/-:/osmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmh.```.--`.-+///o//-.-/.::../-s.s-/:yy/yhhhyyyso:+yyyhyhdhso:://://.:::+o:+/-shmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmh:-` `.`..`:.:...-`:---`-..-/o/+:/ysyhhhhhhyyo+:+hhshyshssos+-+so:+://+:++sso+oodmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmy``..`..```..:..`.`:.--.//o/+/+yys+yhhyhhhyy+::sdyddhhhyoo+o:/ssss/+/yos-/+/++so//+sdmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmm+.```-`:.:-``.-..-`.`:--///s+/ohyhyhhhy+yys/:+hdddyshhyysyyssss/.oyyo/+yoo:oysoo/    `:odmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmd+.`:`.-...-.```+--.:-::-:o-:syoyyyyyyyyy:+/:+sdddhssydyhosossyyh/yhhyyssysyo+ssyo+-``     -ommmmmmmmmmmmmmmmmmmm" <<
    "mmmmmd:    ..:```.`..``..-/--:::/oossssyyyyss+/:::+yddddddhhhhhshhyhhhyyhhhhyhyysosoosso/:```````   .hmmmmmmmmmmmmmmmmmm" <<
    "mmmmm-      `--:`-.----..--++//+/+ooossso+/:-:::/yhhhhhysyyyyhyyyyyyhsyhhhhhysshos++so/:.`````````   /mmmmmmmmmmmmmmmmmm" <<
    "mmmmm/      `..--.--/:::::///++/+ooo+/:------::///++++oossssyssyyysoo+++//+ssso:://:///-.```````    .hmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmo.     `..---.:--::://////o++:..---.`` `-:////////:::::::::------::::::::://++/:-..`        .ommmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmy/.      `...-::-::://:/::-...`````````.-:/++++/////:::::::::::://+++++:/-..`.``      `:ohmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmhs/-`     ``.-::-..```         `````....--:/+++++++++////::::--.``````        `-/ohmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmdys+/-.`    `                ```.......--..```````````           `.:/oshdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmmmmmdhyso+/:-..``                              ``.--:/+osyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddhhhyyyyyyyyyyyyyyyyhhhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";
}

void anvil() {
    cout <<
    " `..```````  `                                                                                                          " <<
    "````````` `                                                                                                             " <<
    "``.```                                                                `.-:://+oohmddyso++/:.`                           " <<
    "                                                        `.-:/+osyyhdmNNMNMNmdhhyyososyhyso+/:-`                         " <<
    "                                           `.-/+osyhddmNNMMMMMMMNNNmmNMMNmmhhyso+/:---..`...-.          `               " <<
    "                                      -+shmMMMMMMNNMNNNNNNMMMmdmmhhhyso+++///:---::-....````                            " <<
    "       :/-`                     -/osyhdhsoss/ssyhmNdhyysyyosyhyyssyo//+/+/:::-:-----.`                                  " <<
    "       ``                    `.-/hNysoddmNmmdhs+o::o++o+///oh+sssoso//////:---:--.`                                 ``  " <<
    "                  `.-//+oyhdddhyyhddysoy//+o++++-.:+///:/+oos+/+o++//::://:::/-.`                                       " <<
    "    ``  `-:+oyhhdddhhhhddddmmNNdhhdyssoo+.:++/+/:-.///-/o++://o++////:::/::::.           ``               ````          " <<
    "    `+ydddhhyysyyyyyyhhhs+//+o+::::::::-:--://::.`--:::--::::/+//::/:-:::::-`            ``                             " <<
    "      ```...--::/++///os++/+o+o/:/:-.-.```.--:---..-:---:::::://////::::--.                                             " <<
    "                  ````.``..-...````  ``   .----.``-----:------::::::------                                              " <<
    "                                          `..``   `......--:::::::://:::/-                                              " <<
    "                                                `         ``-:::/+o++o+os/                                              " <<
    "       `.`                                   `-/:..```      `/+osysyyysss+.       `-`                                   " <<
    "                   `                      `://::-..`.....`` `:yyyyyysso++///-`    ``   `                                " <<
    "                                      `./++//::-.`......``..-+oo+/++//////+osh+-  `                            `        " <<
    "                   ``               -++oso+/::-....```...--::hoo++/.`.```...:oydh+:``                `````              " <<
    "                  ....             `--/++/:::-..........-//:/dyso/.`..`...`.``./sdhyo:.            `    ```            `" <<
    "                                      ``.-::--.....-.--::///oNhss-.`````...-.```..:oo+/`                 `          `   " <<
    "                                           ``.-.------:///++yMmhs.```````     ```````      `  `  `       ```            " <<
    "                                               `.--::://+ooohMmNy.                              `     ``                " <<
    "                                                  `.-:/++ooshmhhs.                                    ``                " <<
    "     .-                                           .   .-/+osdd+os+                            ``       `  `             " <<
    "     ``                                                 `.-:s/:-.                                                       " <<
    "                                             `-```      `   `                                                           " <<
    "                                               `..`                                                                     " <<
    "                                          `      ``                                                                     " <<
    "                                                                                                                        ";
}

int GetConsoleCursorPosition() {
    CONSOLE_SCREEN_BUFFER_INFO cbsi;
    if (GetConsoleScreenBufferInfo(GetStdHandle( STD_OUTPUT_HANDLE ), &cbsi)) {
        return cbsi.dwCursorPosition.Y;
    } else { // The function failed
        return 0;
    }
}

void gotoxy(int column, int line) {
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ), coord);
}

void train() {
    string choo[] = {
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                                                       ",
        "                                              _________                ",
        "                                             |=========|               ",
        "                    __[]__         _          \\_______/                ",
        "+================+ /______\\     __(_)__    ()  \\_____/   ()            ",
        " `-+ +-----+---+ | |------|    /_______\\  /__\\  |   | +======+         ",
        "   | |     |   | +-+------+-.  |=======| <____> |   | ||    ||         ",
        "   | |     |   | |o          \\_|___  __|__//\\\\__|___|_+======+         ",
        "   | +=========+ |o                                     o||=+          ",
        "   | *         * |o                                     o||||          ",
        "   |    --%--    |o~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~o||=+          ",
        "   +=====================================+-----------+====+            ",
        "       |==/ ------ \\=====/ ------ \\===%--||o        o||____            ",
        "         // \\  L_/__\\___//_\\__L_/__\\_/ %=||o~~~~~~~~o||===\\\\_____      ",
        "        ||__ /.  ___________ .  ______/ +==============+      \\  \\_    ",
        "        ||   \\__/   || ||   \\__/   ||     //--\\\\  //--\\\\\\\\   \\ \\ \\\\\\_  ",
        "         \\\\ / || \\ //   \\\\ / || \\ //     (( <> ))(( <> ))\\\\_\\_\\_\\_\\\\\\\\ ",
        "          \\========/     \\========/       \\____/  \\____/  `-----------+"};

    int console_row = GetConsoleCursorPosition();

    for (int i = 70; i >= 0; i--) {
        stringstream ss;
        for (int j = 0; j < 30; j++) {
            for (int k = i; k < 71; k++) {
                ss << choo[j][k];
            }
            ss << endl;
        }
        cout << ss.str();
        // Goes back to the top of the frame
        gotoxy(0, console_row);
        Sleep(50);
    }
    // Goes to the bottom of the frame to resume normal output
    gotoxy(0, console_row+30);
}


int main() {
    train();
}