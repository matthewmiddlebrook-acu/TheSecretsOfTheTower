#include "PrintColor.h"

#include <iostream>
#include <windows.h>
#include <winnt.h>
#include <stdio.h>
using namespace std;


// To use, pass string to be colored, and an optional color enum (defaults to magenta)
// Ex: cout << PrintColor("Hello") << " world! " << PrintColor("Yay!", CYAN) << endl;

ostream& operator<<(ostream& os, const PrintColor& mp) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, mp.c_);
    os << mp.val_;
    SetConsoleTextAttribute(hConsole, WHITE);
    return os;
}

void PrintColor::setOutputColor(int c) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);
}