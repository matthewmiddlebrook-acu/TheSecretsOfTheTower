#ifndef PRINTCOLOR_H
#define PRINTCOLOR_H

#include <iostream>
using namespace std;

enum Color{BLACK, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, WHITE, GRAY, B_BLUE, B_GREEN, B_CYAN, B_RED, PINK, YELLOW, B_WHITE};

class PrintColor {
    public:
        PrintColor(string val, Color c = MAGENTA) : val_(val), c_(c) {}
        friend ostream &operator<<(ostream &os, const PrintColor &mp);

        static void setOutputColor(Color c_);

      private:
        string val_;
        Color c_;
};

#endif