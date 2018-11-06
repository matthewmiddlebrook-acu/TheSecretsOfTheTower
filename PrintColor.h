#ifndef PRINTCOLOR_H
#define PRINTCOLOR_H

#include <iostream>
using namespace std;

enum Color{WHITE, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, BLACK, GRAY};

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