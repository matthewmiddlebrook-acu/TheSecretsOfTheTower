#include <iostream>
using namespace std;

class GameObject {
    public:
        void setName(string n) { name = n; }
        string getName() { return name; }
        string getDescription() { return description; }
        void setDescription(string desc) { description = desc; }
    
    private:
        string name;
        string description;
};