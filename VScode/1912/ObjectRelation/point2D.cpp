#include "point2D.h"

point2D::point2D(int xVal, int yVal){
    this->xVal = xVal;
    this->yVal = yVal;
}

point2D::~point2D(){

}

void point2D::setPoint(int x, int y){
    this->xVal = x;
    this->yVal = y;
}

ostream& operator<<(ostream& o, const point2D& p){
    o << "(" << p.xVal << ", " << p.yVal << ")" << endl;
    return o;
}