#include <iostream>
#include <windows.h>
#include <winnt.h>
#include <stdio.h>
using namespace std;

enum Color{WHITE, BLUE, GREEN, CYAN, RED, MAGENTA, BROWN, BLACK, GRAY};

// To use, pass string to be colored, and an optional color enum (defaults to magenta)
// Ex: cout << PrintColor("Hello") << " world! " << PrintColor("Yay!", CYAN) << endl;

class PrintColor {
    public:
        PrintColor(string val, Color c = MAGENTA) : val_(val), c_(c) {}
        friend ostream& operator<<(ostream& os, const PrintColor& mp) 
        {
            HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
            SetConsoleTextAttribute(hConsole, mp.c_);
            os << mp.val_;
            SetConsoleTextAttribute(hConsole, BLACK);
            return os;
        }

        static void setOutputColor(Color c_) {
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c_);
        }
    private:
        string val_;
        Color c_;
};