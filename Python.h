#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string answer1 = "0000000000001234567891002468101214161820036912151821242730048121620242832364005101520253035404550061218243036424854600714212835424956637008162432404856647280091827364554637281900102030405060708090100";

bool multTable() {

    cout << "Write a python program that outputs the multiplication table for 10. Put only a space between numbers." << endl;
    cout << "Be carful, onve you move ot a line new line you will not be able to change your answer." << endl;
    cout << "Type DONE hit enter on an emptyline to submit your program to Athene." << endl;
    cout << "\nExample Table for 4:\n";
    cout << "0 0 0 0 0\n";
    cout << "0 1 2 3 4\n";
    cout << "0 2 4 6 8\n";
    cout << "0 3 6 9 12\n";
    cout << "0 4 8 12 16\n";
    cout << endl << endl;

    string line;
    ofstream outfile("test.py");
    getline(cin,line);
    while (line != "DONE") {
        outfile << line << endl;
        getline(cin,line);
    }
    outfile.close();
    system("python test.py > output.txt 2>&1");

    string output;
    ifstream infile("output.txt");
    if (infile.is_open()) {
        string num;
        while (infile >> num)
            output += num;
        infile.close();
    }
    if (output == answer1)
        return true;

    return false;
}

bool helloWorld() {
    cout << "Write a python program that outputs \"Hello, World!\"." << endl;
    cout << "Be carful, onve you move ot a line new line you will not be able to change your answer." << endl;
    cout << "Type DONE hit enter on an emptyline to submit your program to Athene." << endl << endl;

    string line;
    ofstream outfile("test1.py");
    getline(cin,line);
    while (line != "DONE") {
        outfile << line << endl;
        getline(cin,line);
    }
    outfile.close();
    system("python test1.py > output1.txt 2>&1");

    string output;
    ifstream infile("output1.txt");
    if (infile.is_open()) {
        string line;
        while (getline(infile,line))
            output += line;
        infile.close();
    }

    if (output == "Hello, World!")
        return true;
    return false;
}