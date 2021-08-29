#include "point3D.h"

point3D::point3D(int xVal, int yVal, int zVal)
    : point(xVal, yVal)
{
    // this->xVal = xVal;
    // this->yVal = yVal;
    this->zVal = zVal;
}

point3D::~point3D(){
    cout << "Huy Point3D" << endl;
}

ostream& operator<<(ostream& o, const point3D& p){
    o << "(" << p.xVal << ", " << p.yVal << ", " << p.zVal << ")" << endl;
    return o;
}

void point3D::show3D(){
    cout << "(" << this->xVal << ", " << this->yVal << ", " << this->zVal << ")" << endl;
}

void point3D::show(){
    cout << "(" << this->xVal << ", " << this->yVal << ", " << this->zVal << ")" << endl;
}