#include "GameObject.h"

#include <iostream>
using namespace std;

string GameObject::lowercase(string s) {
    string copy = s;
    for(auto& elem : copy)
        elem = tolower(elem);
    return copy;
}

bool GameObject::constainsString(string find, vector<string> strings) {
    for (string s : alt_names)
        if (lowercase(s) == find)
            return true;
    return false;
}

bool GameObject::checkName(string value) {
    value = lowercase(value);
    return (value == lowercase(getName()) || constainsString(value, alt_names));
}