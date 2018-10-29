#pragma once

#include <iostream>
#include <vector>
using namespace std;

class GameObject {
    private:
        string _name;
        string _description;
        // Holds alternate names for the object for the user to input
        // For example, an alt name for a Location named "MBB" could be "COBA"
        vector<string> alt_names;

        string lowercase(string s);

        bool constainsString(string find, vector<string> strings);

      public:
        GameObject(string name, string desc) : _name(name), _description(desc) {};

        void setName(string name) { _name = name; }
        string getName() { return _name; }

        string getDescription() { return _description; }
        void setDescription(string desc) { _description = desc; }

        void setAlternateNames(vector<string> alt) { alt_names = alt; }
        bool checkName(string value);
};