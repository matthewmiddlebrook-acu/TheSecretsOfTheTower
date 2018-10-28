#include <iostream>
using namespace std;

class GameObject {
    private:
        string _name;
        string _description;
    public:
        GameObject(string name, string desc);

        void setName(string name) { _name = name; }
        string getName() { return _name; }

        string getDescription() { return _description; }
        void setDescription(string desc) { _description = desc; }
};