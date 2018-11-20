#ifndef ASCII_H
#define ASCII_H

#include <windows.h>
#include <sstream>
#include <iostream>
using namespace std;

// https://www.text-image.com/convert/ascii.html
// Use width of 120
// Image size 960x480

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

void donut() {
    cout <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyooo++/ooyyyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmdyo//--`.-/.-`.:-:++/+shmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmy+---:.-..`..`.-..::://:++//dmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmmmmdds--....`--..:```...`..:o-:-/s+soymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmdyo-..-.-..+.`-..````.`-..-+:+:/+yssoyymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmy/-.`..-+::-:-.......-.`-..--:/::s/yyysyydmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmd/-.---:/:sooo://+/::://:.`.-/:/+o/ss+o+sssoymmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmms---::/:o+/ysyyyoyysssoo+-.-/:://oyyooyssssoshmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmd/`-.`..+yy+osyyyyyyyso+:...//:::/+oooss+osossodyhhdhhdddddhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmo`.--``..ososhyhhhsso++:-..:--:/:///+:++osssyoo/+:oo-+//--://:.:+oyyshdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmms .`--./::++ssydhy:/:---`/-.---/oo+//hysssyyss+:oddhsyyyyso++/+-:o+::/-:/osmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmh.```.--`.-+///o//-.-/.::../-s.s-/:yy/yhhhyyyso:+yyyhyhdhso:://://.:::+o:+/-shmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmh:-` `.`..`:.:...-`:---`-..-/o/+:/ysyhhhhhhyyo+:+hhshyshssos+-+so:+://+:++sso+oodmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmy``..`..```..:..`.`:.--.//o/+/+yys+yhhyhhhyy+::sdyddhhhyoo+o:/ssss/+/yos-/+/++so//+sdmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmm+.```-`:.:-``.-..-`.`:--///s+/ohyhyhhhy+yys/:+hdddyshhyysyyssss/.oyyo/+yoo:oysoo/    `:odmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmd+.`:`.-...-.```+--.:-::-:o-:syoyyyyyyyyy:+/:+sdddhssydyhosossyyh/yhhyyssysyo+ssyo+-``     -ommmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmd:    ..:```.`..``..-/--:::/oossssyyyyss+/:::+yddddddhhhhhshhyhhhyyhhhhyhyysosoosso/:```````   .hmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmm-      `--:`-.----..--++//+/+ooossso+/:-:::/yhhhhhysyyyyhyyyyyyhsyhhhhhysshos++so/:.`````````   /mmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmm/      `..--.--/:::::///++/+ooo+/:------::///++++oossssyssyyysoo+++//+ssso:://:///-.```````    .hmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmo.     `..---.:--::://////o++:..---.`` `-:////////:::::::::------::::::::://++/:-..`        .ommmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmy/.      `...-::-::://:/::-...`````````.-:/++++/////:::::::::::://+++++:/-..`.``      `:ohmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmhs/-`     ``.-::-..```         `````....--:/+++++++++////::::--.``````        `-/ohmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmdys+/-.`    `                ```.......--..```````````           `.:/oshdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmmmmmdhyso+/:-..``                              ``.--:/+osyhdmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm" << endl <<
    "mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmddhhhyyyyyyyyyyyyyyyyhhhddmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm";
}

void anvil() {
    cout <<
    " `..```````  `                                                                                                          " << endl <<
    "````````` `                                                                                                             " << endl <<
    "``.```                                                                `.-:://+oohmddyso++/:.`                           " << endl <<
    "                                                        `.-:/+osyyhdmNNMNMNmdhhyyososyhyso+/:-`                         " << endl <<
    "                                           `.-/+osyhddmNNMMMMMMMNNNmmNMMNmmhhyso+/:---..`...-.          `               " << endl <<
    "                                      -+shmMMMMMMNNMNNNNNNMMMmdmmhhhyso+++///:---::-....````                            " << endl <<
    "       :/-`                     -/osyhdhsoss/ssyhmNdhyysyyosyhyyssyo//+/+/:::-:-----.`                                  " << endl <<
    "       ``                    `.-/hNysoddmNmmdhs+o::o++o+///oh+sssoso//////:---:--.`                                 ``  " << endl <<
    "                  `.-//+oyhdddhyyhddysoy//+o++++-.:+///:/+oos+/+o++//::://:::/-.`                                       " << endl <<
    "    ``  `-:+oyhhdddhhhhddddmmNNdhhdyssoo+.:++/+/:-.///-/o++://o++////:::/::::.           ``               ````          " << endl <<
    "    `+ydddhhyysyyyyyyhhhs+//+o+::::::::-:--://::.`--:::--::::/+//::/:-:::::-`            ``                             " << endl <<
    "      ```...--::/++///os++/+o+o/:/:-.-.```.--:---..-:---:::::://////::::--.                                             " << endl <<
    "                  ````.``..-...````  ``   .----.``-----:------::::::------                                              " << endl <<
    "                                          `..``   `......--:::::::://:::/-                                              " << endl <<
    "                                                `         ``-:::/+o++o+os/                                              " << endl <<
    "       `.`                                   `-/:..```      `/+osysyyysss+.       `-`                                   " << endl <<
    "                   `                      `://::-..`.....`` `:yyyyyysso++///-`    ``   `                                " << endl <<
    "                                      `./++//::-.`......``..-+oo+/++//////+osh+-  `                            `        " << endl <<
    "                   ``               -++oso+/::-....```...--::hoo++/.`.```...:oydh+:``                `````              " << endl <<
    "                  ....             `--/++/:::-..........-//:/dyso/.`..`...`.``./sdhyo:.            `    ```            `" << endl <<
    "                                      ``.-::--.....-.--::///oNhss-.`````...-.```..:oo+/`                 `          `   " << endl <<
    "                                           ``.-.------:///++yMmhs.```````     ```````      `  `  `       ```            " << endl <<
    "                                               `.--::://+ooohMmNy.                              `     ``                " << endl <<
    "                                                  `.-:/++ooshmhhs.                                    ``                " << endl <<
    "     .-                                           .   .-/+osdd+os+                            ``       `  `             " << endl <<
    "     ``                                                 `.-:s/:-.                                                       " << endl <<
    "                                             `-```      `   `                                                           " << endl <<
    "                                               `..`                                                                     " << endl <<
    "                                          `      ``                                                                     " << endl <<
    "                                                                                                                        ";
}

void walk() {
    string walk[] = {
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                   .rLjJuLr.                \n"
        "                                                 :28NX1S15U57               \n"
        "                                                LkN0EPNPP27:Sr              \n"
        "                                               7XrXGEZ00kSjJUU              \n"
        "                                               NGqGZMMOqP55107              \n"
        "                                               GM8ZMMBM8qNqMk               \n"
        "                                               :BBBBBEMBBBBF                \n"
        "                                                 kMBMSBBBq,                 \n"
        "                                                 :vrLLr                     \n"
        "                                               :uU77:ri                     \n"
        "                                           ,rYEBBMZSr Yi                    \n"
        "                                          LBGqBB80FkUvUL                    \n"
        "                                          BB2ijU2UFUuYF:                    \n"
        "                                          0ZUYv25NkFUUL                     \n"
        "                                         :FLvLUU5U5ujJU7Ljk27               \n"
        "                                        .BBMXF21uuJL.iMBBBBBB.              \n"
        "                                         NBBBZNkPkP17;77LPMS,               \n"
        "                                          iBBB1PqOBBMGUr.                   \n"
        "                                            UBBMBM2OBBBO7                   \n"
        "                                            ,GOBBE 7POMP                    \n"
        "                                            rGBBG7u10GU                     \n"
        "                                           .UXJ7:L8BO;                      \n"
        "                                          ,FBjrYuLL7                        \n"
        "                                        :UGBBBNBMN7:                        \n"
        "                                      JBBBBBBBBBBBBPY7.                     \n"
        "               ..::iii:i:i:i:::::::::i8BBBMMGOZNuMBBNP,                     \n"
        "                . ........... ... . .                                       ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                    ,::,.                   \n"
        "                                                .71XSS5k11r                 \n"
        "                                               LGG0XkFk12;YY                \n"
        "                                              UL2GN0P0Pk27rXi               \n"
        "                                             L8jP0M8MNq5522ki               \n"
        "                                             qOGq8OBO8XPFSNk                \n"
        "                                             UB8OOBBB8GN8MG.                \n"
        "                                              EBBBBZqBBBBJ                  \n"
        "                                               :kBBBBBNi                    \n"
        "                                                 .jU7                       \n"
        "                                          ,7Liiir7rir7.                     \n"
        "                                         2BBBBBBBBq5:,u:                    \n"
        "                                        UBMU.iBZM0NSU 7Y                    \n"
        "                                      :U212  ::L12U5UY27  .JXS7             \n"
        "                                    .FBNUvi :i7q0XN1UYri:UBBBBB.            \n"
        "                                    iBBBBZ .XSNNkPFUuu::qBBBBM:             \n"
        "                                     :8Ej  rGSqXqkSU1SNkY.                  \n"
        "                                           UOGZOXX5PqZEM,                   \n"
        "                                           iBBB80qGZ8kk:                    \n"
        "                                            iBBBBO1NEq7                     \n"
        "                                             :BO2irYUL.                     \n"
        "                                             .5Xr2GqYv7i                    \n"
        "                                          ..75GBBBBBBBBN1Y:                 \n"
        "                                     JSFj1ZBBBBBBr .YBBBBB;                 \n"
        "                                    .BBBBBBBBBBj       ,i.                  \n"
        "             ..,:::i:i:::::i:i::::::.rEM8MMEUX2                             \n"
        "              ................... .                                         ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                  .iYUF11jL,                \n"
        "                                                .JEOqPFk15YUr               \n"
        "                                               :XkG0EqEPP1riP:              \n"
        "                                              ,ZrUZOZGE0kSUUSr              \n"
        "                                              XG0EGGBMGqP5FSE.              \n"
        "                                              0M0ZGMBB8ENqEBr               \n"
        "                                              7BB8BBOZBOBBB;                \n"
        "                                               rBBBBOBBBBu                  \n"
        "                                            ,,   rOG8EY.                    \n"
        "                                         .PBBBBSr;i;ir                      \n"
        "                                       :UZBBPSBBBMG2rr2i    ,7L:            \n"
        "                                    iJUFLkv.   EPMZNUYiU,  iOBBBi           \n"
        "                                   YBBMUXi    rLU212kY7u: rBBBBN            \n"
        "                                   iBBBBr    77;NNSPUUJY7SBBBY.             \n"
        "                                     ,:     ,u:qZX05UYJrrkY                 \n"
        "                                            5YYZXPX5uujFv;                  \n"
        "                                           ,MNMZEPPSPNMM8F.                 \n"
        "                                            MBMBEZEMNBBBGF.                 \n"
        "                                            :BBBBMBi  uBMF:                 \n"
        "                                             NMBXBB   .0PU7rirri            \n"
        "                                            ,F0FSB,   j5XukMBBBB;           \n"
        "                                           iU5X0B7   :BBBBBBBBEr            \n"
        "                                    iiii7uZMMMBBi     .i:                   \n"
        "                                   BBMq0NOBBBO7                             \n"
        "                                   jBBBBZ21U                                \n"
        "               ..,::::::::::::::::. i0MM8PUi                                \n"
        "                . ...............                                           ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                       .::i:,               \n"
        "                                                    :uP0FS1S12r             \n"
        "                                                  .j00EqPSPF5;LY            \n"
        "                                                 .PLrENGEGqX2jYk:           \n"
        "                                                 jOk0qE8MZEkkUSX.           \n"
        "                                                 XOENG8BBM00X0OY            \n"
        "                                                 .MOMMBMXOBMBBL             \n"
        "                                           iv15J. iFNBBMBBBBG.              \n"
        "                                    ,LYirj0BBBBBBF7;rrLv1r:   .             \n"
        "                                   rBBO2YZ8Ui .2MBMEJriv    :OB8v           \n"
        "                                   :BBBBMj.     FN8qFu7:v  .8BBB2           \n"
        "                                     7u7.      LUUYuU5rrL ,MBBqr            \n"
        "                                              LLS1F15uuLY2ZEJ               \n"
        "                                             77rPqXP2UYuMBZ.                \n"
        "                                            .P1NZq0k52X7,,                  \n"
        "                                            78NG0q52UXr                     \n"
        "                                            r8ZEGP5L7r                      \n"
        "                                            iOqOMM0kL:::                    \n"
        "                                            vPMMBBBBON5jL.     iqPL         \n"
        "                                          :kEBBBE:JBBBBMkY:   :XMMq.        \n"
        "                                        :UOBBBBL    :ZBBBBX7::UPMZr         \n"
        "                                   ..iuqMBBBBS         7NBBBMkYUFj          \n"
        "                                 FMk1EBBB82:              vBBBBBX           \n"
        "                                 OBB2YJi                    :OBq.           \n"
        "                                  ZBM1Y:                                    \n"
        "               ..::::::::::i::::,.:8MGkY ...............                    \n"
        "               ..................         . . . . . .                       ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                   .i7YLv;:                 \n"
        "                                                 7XZkk12212U:               \n"
        "                                                UUXN0kXSFUriS,              \n"
        "                                               j0LSGGGEEkFYY2Y              \n"
        "                                               qM0GEMMMEq5S10r              \n"
        "                                               7BOGMMBMMEN0MF               \n"
        "                                           ,i,  jEMBBMZBBBBL                \n"
        "                                     ...:qBBBBB2rr7uXPqB07                  \n"
        "                                   UB82LNBBUrXBBO5Ji,:L     .,,             \n"
        "                                  ,BBBGqPr    7MMBEk:,J    jMBZU            \n"
        "                                   2BBBj.     YjS2127iU   1BBBBJ            \n"
        "                                             Yiu5UUU7vY.,8BBkY.             \n"
        "                                            iU7qNSXujLjZBqJ.                \n"
        "                                            FP0GN0kFu2UBY                   \n"
        "                                           iZqGNN51J1j                      \n"
        "                                           1MZGONSJL7,                      \n"
        "                                           iBOMMBEFY;:.                     \n"
        "                                            5BOMMBBMq1Y:                    \n"
        "                                            v0BBBBBBBBEJ7                   \n"
        "                                          .72MBBB  YBBBMF7.                 \n"
        "                                 .UUY7LjU5EZOBBB.    JBBBGXi                \n"
        "                                 LBBNFXOBBBBB0i        :BBBPY7rJJU1Nu.      \n"
        "                                  JBBMkjPr.              7BBBMMBBBBB8       \n"
        "         :i::::i:::::i:i:::::i:::. LMBP2r      .........  iMBBEOkur:        \n"
        "         ,:,:,,,,.,..............               .                           ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                   :;r7ri.                  \n"
        "                                                .jqN55U5U5L.                \n"
        "                                               :55ZXXSSUui7U.               \n"
        "                                               8YjZG00PX27rF7               \n"
        "                                              iB8NZZMZEkFUUFY               \n"
        "                                               MOGGMBMZNSkqE.               \n"
        "                                               ,MMBBBBBMBBO.                \n"
        "                                          .:.   .22GM8MBG7                  \n"
        "                                        iN8MBBNuL7riir7                     \n"
        "                                      :UZBNJkBBBBMXL :i                     \n"
        "                                    ,UXuJJ.  ;PqGkP17rU    .::              \n"
        "                                   YBBG5j:   7.1U2UULjY  .1BBBq.            \n"
        "                                   7BBBB0   u:vPS15JYLL:uMBBBBU             \n"
        "                                     7L:   :PSNEqq5UYY5BBB0Ji.              \n"
        "                                           YZNZPq12Yv7r                     \n"
        "                                           NZGGOqk2Ur:                      \n"
        "                                           qBMBMZP8E0Uur.                   \n"
        "                                           ,BBB85ZBBBB81L.                  \n"
        "                                             ZMOBBq.0MMNk:                  \n"
        "                                    :7;:     L5EBBr .OMMX:                  \n"
        "                                   XBOXUuYYJkN8MBB   ZBGk                   \n"
        "                                   :BBBGXXNBBBBBU   ,E0F7                   \n"
        "                                     iBBBNkPr       5k1YjUS5F7.             \n"
        "             ..,,::i:i::::::::::::,:. :8Mq2i     . LBBMEGBMGqE;             \n"
        "              ..................... .                                       ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                   .:r7Lr:.                 \n"
        "                                                 :qE0FS5S1SL.               \n"
        "                                                L1P8qNXP5U:LU.              \n"
        "                                               rMLXGOGGqX1L7Xi              \n"
        "                                               2M8ZZMBGEqk15Pi              \n"
        "                                               iBMMOBBB8EqEMX               \n"
        "                                                LBBBBMZBBBBF                \n"
        "                                                  5BBMBBB2.                 \n"
        "                                                 .i77L.                     \n"
        "                                         :jYLvjk8NU777.                     \n"
        "                                        vB8BBBBBBBq5r:U                     \n"
        "                                       rM27.:G0PkU52L7F.                    \n"
        "                                      :N57, .JY1U522Ljj                     \n"
        "                                     YMONLi7SXNqEqXUuJv .;vi.               \n"
        "                                    .BBBBBMBM8NZEN52YU0BMBBBJ               \n"
        "                                     rBMU,7BM0G0q1Uvr78BBBBZ.               \n"
        "                                           PMOBB0P557:   .                  \n"
        "                                           :BBBBBMBMZj:                     \n"
        "                                            ,BBBMBBBM8jY.                   \n"
        "                                             rNZBB8UZZNX:                   \n"
        "                                    ,ri:..,i71ZBBB1JEBOU                    \n"
        "                                   7BBE1SPNGBBBBBiikMOU                     \n"
        "                                   .BBBGXPOBMk;.  JX5j,                     \n"
        "                                     uBBMYM.    Y8ZS5UFqGP7                 \n"
        "              .,:::ii;iiii:::::::i::..UBEFk,   :BBBBOBBMGOr                 \n"
        "              .....................                                         ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                    .iir;i,                 \n"
        "                                                 .LX0SX5F15ui               \n"
        "                                                iP0ZqPkPS5L:Ur              \n"
        "                                               7XiP0G0GqPFU7U2              \n"
        "                                               MqP0EGMGEXS25SU              \n"
        "                                              .BO0EEBBB00XN0G,              \n"
        "                                               JBBMMBE0BMBBO,               \n"
        "                                                rOBBBBBBB87                 \n"
        "                                                  iG0v;:                    \n"
        "                                                :irri                       \n"
        "                                              iXNPJvL1:                     \n"
        "                                          .v1ZB88XFur:1                     \n"
        "                                         ,BBqMMq21U1ii1.                    \n"
        "                                         LB57vuJFkXUuU2                     \n"
        "                                         :PUr7LU2S25uSi                     \n"
        "                                         ,UUUYuJUJUuSU                      \n"
        "                                         SBB8P21uJLLYu;:                    \n"
        "                                         :BBMNMNkJvrEBBk.                   \n"
        "                                           jBBBBN577OBG:                    \n"
        "                                             5OZOXu;                        \n"
        "                                             iFX0EUJ.                       \n"
        "                                          ,7kZGFNZqU7                       \n"
        "                                    ;jY2NBBBBBBX5MEP7                       \n"
        "                                   rBBXjBBBBO7  PMZF.                       \n"
        "                                    OBNLMv     .8OFY                        \n"
        "                                    7BBUM:     7BPU7jjFXNj.                 \n"
        "             ..,,::::i:::::i::::::,.7M8kPi ....NBBG88BMM8q.                 \n"
        "              . ...................         .                               ",

        "                                                    .ii;:,                  \n"
        "                                                 .YP0XXSk52:                \n"
        "                                                7OZ8qNPP1J:Ui               \n"
        "                                               7U7GZZNEXSu7J2               \n"
        "                                              .M1k0O8MNqF1U1U               \n"
        "                                              iMG0Z8BMGXPFkE7               \n"
        "                                              .BMGGBMB8GqGBF                \n"
        "                                               rBBBBOkBBBBL                 \n"
        "                                                 YMBBBBB7                   \n"
        "                                                  iY:                       \n"
        "                                               Y5U7rr.                      \n"
        "                                              5NZNk7v1i                     \n"
        "                                             Y00P0S1:;Y                     \n"
        "                                           .uqXFF2F5YY2                     \n"
        "                                           PZOkS2k2LvPL                     \n"
        "                                          .0ZqP55jY:ru                      \n"
        "                                          iG5qPqSULv7:                      \n"
        "                                          7BEqZ0ZEGFF:                      \n"
        "                                           NZZEBMBBBF                       \n"
        "                                           iMZBBB8BJ                        \n"
        "                                           :ZOEkYYUi                        \n"
        "                                           .GEXY7YP.                        \n"
        "                                           .P8Puv1:                         \n"
        "                                       :7Yk5SG81Y                           \n"
        "                                     .NBBBBBXMZkr                           \n"
        "                                     .BBBBB.YBMF;                           \n"
        "                                      SBBBX :G2vi  ...                      \n"
        "                                      jBBBB jBEUk0GZMME.                    \n"
        "               ..,,:::::::::::::::::,.rMMBU YBBMOBBBBBk.                    \n"
        "                ................. .                                         ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                 :rjUUJv:                   \n"
        "                                               iNMGkP5F25j,                 \n"
        "                                              r2kOEENq51:71.                \n"
        "                                             :MYkZM88PX2uYXi                \n"
        "                                             YM8E8OB8Ekk2Fq:                \n"
        "                                             :BMOOBBBGZP0M2                 \n"
        "                                              vBBBBMZBBBBU                  \n"
        "                                               .SBBBBBB1.                   \n"
        "                                                  .,                        \n"
        "                                               rYv7r:                       \n"
        "                                             ,USEkj7JU                      \n"
        "                                          vZOj.JBMqvJF,                     \n"
        "                                         GBBG7j8NN2JY5                      \n"
        "                                        .OBFiiEkX1U7L7                      \n"
        "                                        r1L7.2Z0XSJ7r7                      \n"
        "                                       :MS5J2GEqPX8G0k2FNkJ                 \n"
        "                                       7BBE0ZM0XJUMBBMkBBBB,                \n"
        "                                        rU58OO81v1BBBBBBBMi                 \n"
        "                                           ;MMGkrZBBBBF                     \n"
        "                                            8MMF77BMMqj                     \n"
        "                                            2M0XviY8BB:                     \n"
        "                                            U8E1Lv0BS                       \n"
        "                                            SMN1JM8;                        \n"
        "                                           FBB8S7                           \n"
        "                                          iMM0Uu:                           \n"
        "                                        ij5uUL7vUuL.                        \n"
        "         .   ....,,:::::::::::::::,:,:.UBBMMMMG00MML                        \n"
        "          . ....:,:,:.............. .                                       ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                               .:77Yvr,                     \n"
        "                                             .uN055U2u5Ui                   \n"
        "                                            .2UEXP5XUUi:Ui                  \n"
        "                                            EUuNGN0kFUYr2U                  \n"
        "                                           .M8N0EMZqFFUU1U                  \n"
        "                                            XBOZMBBGNkPqZ,                  \n"
        "                                             0BBBB2BBBBG.                   \n"
        "                                              :uGMkkqU:                     \n"
        "                                                .7rr                        \n"
        "                                          YY7::JU77rY:                      \n"
        "                                        iBBBBPi7NqF;:5.                     \n"
        "                                       7BBB,7i:X800urU:                     \n"
        "                                     .2BBB  r.1q1XS17Y.    i77:             \n"
        "                                    iMBBBB;r:7GXk15UY7vLUE8ZB8G:            \n"
        "                                    :BBBBOj7,PkPSF1qE8GBBBBBBBq.            \n"
        "                                      ::. :k0PX52juFBBBBi :7L:              \n"
        "                                          LB8Ek5L7r0BBBB                    \n"
        "                                          .GBM8FY;rkBMX                     \n"
        "                                            UBOG27iYMU                      \n"
        "                                             uMEqY77.                       \n"
        "                                             :EO0FL;                        \n"
        "                                            .7NGOFUJLi                      \n"
        "                                       ..,rUSPXZSkBBMZu                     \n"
        "                                     2OqqXNNZNP5  :MBBS                     \n"
        "             ..:,:::,:,:,:,:,:,:,:,.rBBBBBBMNNSY                            \n"
        "            ..:::::::,,............                                         ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                 ,:rr7i:                    \n"
        "                                               iXkX25u2U1i                  \n"
        "                                              L5qq5k2Fj7:u7                 \n"
        "                                             jF70qNXqF1LrLF.                \n"
        "                                             000XE8GPX12jUF.                \n"
        "                                             FBEEGBM8XPFXEr                 \n"
        "                                              ZBBBBkNBMBM7                  \n"
        "                                               i8BBSq8N7                    \n"
        "                                           ,i.   ,YY7r                      \n"
        "                                        :uBBBBG7:r7i;7r                     \n"
        "                                     LuFS8BBYENUUXF2v;vr     .ivv;          \n"
        "                                   ,BBBZB8:   YvkkN0Xr7i   :kPMBM87         \n"
        "                                   ,BBBB7    U.JS1U552ri,YEBBBBBBE          \n"
        "                                     ..     7viqq55J211PBBOU:,ii,           \n"
        "                                            Y,2NkqFUYEBBU.                  \n"
        "                                           rJYNFkU2UJjFY:                   \n"
        "                                           kZZPXuYLkMMEXjr                  \n"
        "                                           JBM8XU77:;PBMGj                  \n"
        "                                            YB8ZUvr   GMZ1                  \n"
        "                                             vOqkuu.  5MP7,.;7Yr.           \n"
        "                                             i08NqS:  v82JUZMBBB:           \n"
        "                                     ..   .:rU8MBML   XBBBBBBqv             \n"
        "                                   ,Nq1UvJSNSNBBNi     ii:.                 \n"
        "                                   :BBBMON8ZNS7.                            \n"
        "         :::::::::::,:,,.,.:,:,,,,. :EBBBBOqUi   .                          \n"
        "         :r:i::::,,.............. .                                         ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                      ,i;ri:                \n"
        "                                                   ,2qqkS5F5Fr              \n"
        "                                                  LEEZPqkq1UiLY             \n"
        "                                                 jUrZ0GNZXkULvP,            \n"
        "                                                .Mk0qZ8MNNSS25X,            \n"
        "                                                :B8NZGBBMNNkq8J             \n"
        "                                                 PBMOBBZMMOBBU              \n"
        "                                                  UBBBBBBBB0:               \n"
        "                                                    ,7YUvi                  \n"
        "                                          .iPBBB;   ,          ;L7:         \n"
        "                                     7EO1OBBBBBBM1UXuuYL.    ,FBBB8i        \n"
        "                                    rBBB80OU,  7uUqqZ01Lu   YBBBBBN         \n"
        "                                     8BBX:     YUFU22kP1;::GBBBXv,          \n"
        "                                              v7YF5U2Lj5PNBBP.              \n"
        "                                             ,SrFGqqSULPBBMi                \n"
        "                                             LYXMZ8NX1kXr                   \n"
        "                                            .YiNPNkPPOX.                    \n"
        "                                            vkNqPjJJSU                      \n"
        "                                            7BMG5YrLLi                      \n"
        "                                            L8O0FYjkZUu7:     :1Gk:         \n"
        "                                           .u8Z0SuqBBBB8XU:   UOM8:         \n"
        "                                         .75NGBM2  .LOBBBBELir2GM2          \n"
        "                                       rUNEMBBNi       7BBBBMq1q0i          \n"
        "                                 iJLvJMBBBBBk:            ;NBBBBU           \n"
        "                                LBBZUFBBM5:                 .uUi            \n"
        "                                 ZBBkv7:                                    \n"
        "              ..,:,:,:,:,:,:,,.. ,MBBEU: ..........,...                     \n"
        "              ....,.......... . .                                           ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                   :r7YLYr:                 \n"
        "                                                 Lk0SF25U2UJ.               \n"
        "                                               ,2uNXNXqSSui;F               \n"
        "                                              .GvLNNNEqq55JjF:              \n"
        "                                              U0Nq0NOZZXk211k               \n"
        "                                              UOqE0MMBZEPqZO:               \n"
        "                                               qOGBBBBBMBBG,                \n"
        "                                            :Lv0SUUk11YkFi    .::,          \n"
        "                                        .:2BBBB0rr7ii:i:     v8BB0v         \n"
        "                                    ,1qUFBBBU::uLu2FUj77    JBBBBBi         \n"
        "                                    BBBEqBY    YLFSSPPF7: iMBBBSr           \n"
        "                                    rBBMr     LirXUUYju15SkO5,              \n"
        "                                             :7,kkXF5Y7PBBM,                \n"
        "                                            .S7XENNP22UqL:                  \n"
        "                                            YuNEZ00SSkP.                    \n"
        "                                           .j2qNXk5XN5                      \n"
        "                                           7E0ES2YuU1i                      \n"
        "                                          .PZO0PSEOG1Y7,                    \n"
        "                                         iUSOEON:;BBBMqY:                   \n"
        "                                      .ruN0OMB2.   iGBB8uv                  \n"
        "                                   .;u0ZMBBM2.       rBBBq7.                \n"
        "                              .LjJJNGMMBBPi            1BBZJi:,::;i,        \n"
        "                              kBBG0k5U2r                ,MBBBOBBBBBG.       \n"
        "             ..,,:::::::::::,.:BBBBBZSY. ..............  :2k2555UUj:        \n"
        "            ..,...,........ .                                               ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                    ...                     \n"
        "                                                :jUF222UL:                  \n"
        "                                              ,U0qXU521Y7Yr                 \n"
        "                                             :Fr1ZqqXP1Ui7F,                \n"
        "                                             XNUNN800kSUUYk:                \n"
        "                                            .M0EPGMM0NkF2qF                 \n"
        "                                             XBEMMBBBG8EME,                 \n"
        "                                              58X88MPXPMU.                  \n"
        "                                           .: ,L77rii:v.                    \n"
        "                                         .OBBBYYYuYYrir      L2SY:          \n"
        "                                        vBBBii77PPE0k77    rMBBBBS          \n"
        "                                     :iEBBG  ;:uXS2kSFL:.LMBBBBBP.          \n"
        "                                    ZBBBBM  ,7rNXSFLYSZ0MBB2i.              \n"
        "                                   .BBBB0   UL1NFX2J78BBN:                  \n"
        "                                     ,:    vqXZqN55JJ1:                     \n"
        "                                          .80G8M0P1UL7                      \n"
        "                                          .88GM00P0XkUJi                    \n"
        "                                           FGMEkUXMBBBNUr                   \n"
        "                                           LO0qUu  .XMMPF.                  \n"
        "                                          .Uq0kNr   rMMGU                   \n"
        "                                        :75kO8OL    vBBq:                   \n"
        "                                 i7vr7v10MOBB0:     7X1u.                   \n"
        "                                JBBBMOGEO0Ou.      JOkS2SSXX5,              \n"
        "           . ,,:::::::::.,,,.,..:BBBBBO85ui   ....,PZNUPkk5X5i              \n"
        "          . ..,........ . . . .                                             ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                  .:::.                     \n"
        "                                               ,UXkFS1F2j.                  \n"
        "                                              vGZNFk55u7rF,                 \n"
        "                                             LUv8EEP0FF7iU2                 \n"
        "                                            .Mq0EM88qP11U12                 \n"
        "                                            .MM08MB8GPP5S07                 \n"
        "                                             SBBMBBBMMGMB2                  \n"
        "                                              UMMMB80qB8;                   \n"
        "                                               iYLr7iv.                     \n"
        "                                              :UULL7r7,                     \n"
        "                                          ,UjJYFq0Pk:7L                     \n"
        "                                         rBBB7.k0qZPuL7    .jSS7.           \n"
        "                                         kBBJiYGkqSqUvi .78BMBBBr           \n"
        "                                        iGX77jG00PF2P5EBBBBBBBBU            \n"
        "                                       .5u7LUNEGNP5NMBGX7i..,:              \n"
        "                                      .BBF5F0ZMZ0kFUNr                      \n"
        "                                       MBBMM8BMGXP1ur:                      \n"
        "                                          rMBBMPS5NZEUj:                    \n"
        "                                           .GMGqLYMBBBEu                    \n"
        "                                            2EOXjrLNGZ0L                    \n"
        "                                           :L1XPS,.5Xqk,                    \n"
        "                                   ,i::,;YqZOMB0: YBBNi                     \n"
        "                                  PBMP11uZBBBBL  :Y12L:,,.                  \n"
        "                                  rBBBBB01kPi   GBMqGEOOBBr                 \n"
        "             ...,:::,,,,.,.,.,.,..  rGBBO01v   ,0BZEkXqNkU.                 \n"
        "            . .,:.,.. . ... . .                                             ",

        "                                                                            \n"
        "                                                                            \n"
        "                                                                            \n"
        "                                                 .ir7ri.                    \n"
        "                                               iF8qX1S1kU:                  \n"
        "                                              jP8EqXq557i1r                 \n"
        "                                             YkLEMZG0P5JiUk.                \n"
        "                                             XMEZ8B88XP15UN                 \n"
        "                                             kBMGBBBO8NNXMv                 \n"
        "                                             .BBBBBBBMBBBj                  \n"
        "                                               5q8GZSUSS,                   \n"
        "                                               iuv7rvrv                     \n"
        "                                              7S21UU .U.                    \n"
        "                                             7FJGqXU .X.                    \n"
        "                                           ,ULrZEEXUvUU                     \n"
        "                                          ,MqrkGGNPUYr7  .ii,               \n"
        "                                           U2qG800XPF52ZXMBBN:              \n"
        "                                           5ZGM8ZPNMBBBBBBBBB.              \n"
        "                                          :BGMM8XUkBk. i1MqL                \n"
        "                                           BBMBEF7PB                        \n"
        "                                           ,MBMO1LvX                        \n"
        "                                            :MMZXLLui                       \n"
        "                                             YUFuYYX;                       \n"
        "                                         .:7XqZ2YL1k.                       \n"
        "                                   ,USU1NMBBBBBB8ZSU                        \n"
        "                                   BBBN58BBBkr  MBGU                        \n"
        "                                   7BBNY::      5MPY.                       \n"
        "                                    iBBBUv     7BZXFEEG0X;                  \n"
        "         .   ..:::::::,:,:,:::,:,:.. qBBMk:....28ZSXNNFS2v                  \n"
        "          . ....,.............. . .                                         "};

    int console_row = GetConsoleCursorPosition();

    for (int j = 0; j < 5; j++) {
        for (int i = 0; i < 17; i++) {
            cout << walk[i] << endl;
            gotoxy(0, console_row);
            Sleep(50);
        }
    }
    gotoxy(0, console_row+30);
}

void train() {
    string choo[] = {
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
        for (int j = 0; j < 17; j++) {
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
    gotoxy(0, console_row+17);
}

void assignment(string course, int num) {
    if (course == "PROGRAMMING") {
        
    }
    else if (course == "SCRIPTING") {
        
    }
    else if (course == "ANIMATION") {
        if (num == 1)
            train();
        else
            walk();
    }
    else if (course == "3D MODELING") {
        if (num == 1)
            donut();
        else
            anvil();
    }
    else if (course == "BUSINESS") {

    }
}

#endif