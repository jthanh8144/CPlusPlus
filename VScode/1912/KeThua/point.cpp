#include "point.h"

point::point(int x, int y){
    this->xVal = x;
    this->yVal = y;
}

point::~point(){
    cout << "Huy Point" << endl;
}

ostream& operator<<(ostream& o, const point& p){
    o << "(" << p.xVal << ", " << p.yVal << ")" << endl;
    return o;
}

void point:: show(){
    cout << "xVal = " << this->xVal << ",yVal = " << this->yVal << endl;
}