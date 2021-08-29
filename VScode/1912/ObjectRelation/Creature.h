#include <iostream>
#include <string>
#include "point2D.h"

using namespace std;

class Creature{
    string name;
    point2D location;
    public:
        Creature(const string&, const point2D&);
        ~Creature();
        friend ostream& operator<<(ostream&, const Creature&);
        void moveTo(int, int);
};