#include "point3D.h"
#include <iostream>
using namespace std;

int main(){
    /*point3D p(4, 5, 6);
    p.show3D();
    point3D *p = new point3D(2, 3, 4);
    p->show3D();
    delete p;*/
    point p1(1, 2);
    point3D p2(2, 3, 4);
    point *p;
    point3D *p3d;
    p =&p1;
    p3d = &p2;
    p1.show(); //xVal, yVal
    p2.show(); //xVal, yVal, zVal
    p->show(); //xVal, yVal
    p3d->show(); //xVal, yVal, zVal
    p = &p2; //upcast
    p3d =static_cast<point3D*>(&p1); //downcast
    p->show();
    p3d->show();
    /*point *p = new point3D(2, 3, 4);
    delete p;*/
    /*point3D p2(4, 5, 6);
    point p1 = p2; //slicing
    p1.show();*/
    /*point p1(1, 2);
    point3D p2(2, 3, 4);
    cout << p1 << endl;
    cout << p2 << endl;*/
    return 0;
}