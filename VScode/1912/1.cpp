#include "point.h"
//#include "TG.h"
#include <iostream>
using namespace std;

int main(){
    /*point p1;
    point p2(2, 3);
    point p3(p2);
    //cout << p1.xVal << ", " << p1.yVal;
    p1.show();
    p2.show();
    p3.show();*/
    /*point *p = new point(3, 4);
    p->show();
    delete p;
    cout << endl;
    cout << "abc" << endl;*/
    //point p1(2, 3), p2(4, 5);
    /*p1.show();
    p2.show();
    p1.Set_xVal(p2.Get_xVal());sdfg./., 
    p1.show();*/
    //Display(p1);
    /*point p1;
    point p2(2, 3);
    point p3(p2);
    p1.show();
    p2.show();
    p3.show();*/
    /*point::PrintCount();
    point p1 = point() ;
    point::PrintCount();
    p1.PrintCount();*/
    /*TG t1(1, 2, 3, 4, 5, 6);
    t1.Show();*/
    /*point p1(1, 2), p2(2, 3);
    point p3 = p1 + p2;
    point p4 = operator+(p1, p2);
    p3.show();
    p4.show();
    point p5 = p1 - p2;
    point p6 = p1.operator-(p2);//p1-p2
    point p7 = p2.operator-(p1);//p2-p1
    p5.show();
    p6.show();
    p7.show();*/
    /*point p1(1, 1);
    //cin >> p1;
    operator>> (cin, p1);
    cout << p1;
    operator<< (cout, p1);*/
    /*point p1(1, 2);
    point p2 = p1 +1;
    point p3 = 1+ p1;
    p2.show();
    p3.show();*/
    point p1(1, 2);
    point p2 = ++p1;
    cout << p1 << p2;
    point p3(1, 2);
    point p4 = p3++;
    cout << p3 << p4;
    return 0;
}