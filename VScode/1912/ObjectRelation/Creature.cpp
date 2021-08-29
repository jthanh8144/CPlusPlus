#include "Creature.h"

Creature::Creature(const string& name, const point2D& location)
    : name(name), location(location){

}

Creature::~Creature(){

}

void Creature::moveTo(int x, int y){
    this->location.setPoint(x, y);
}

ostream& operator<<(ostream& o, const Creature& c){
    o << c.name << " is at " << c.location << endl;
    return o;
}