#include "point.h"
//#include <iostream>
//using namespace std;

int point::n = 0;

void point::PrintCount(){
    cout << point::n << endl;
};

int point::Get_xVal(){
    return this->xVal;
}

void point::Set_xVal(int new_xVal){
    this->xVal = new_xVal;
}

void point:: tt(int n){
    this->xVal += n;
    this->yVal += n;
}

void point:: show(){
    cout << "xVal = " << this->xVal << ",yVal = " << this->yVal << endl;
}

point::point()
    : xVal(1), yVal(1)
{
    point::n++;
    /*this->xVal = 2;
    this->yVal = 2;*/
}

point::point(int x, int y)
    : xVal(x)
{
    this->xVal = x;
    this->yVal = y;
}

point::point(const point& p)
    : xVal(p.xVal), yVal(p.yVal)
{
    //this->xVal = p.xVal;
    //this->yVal = p.yVal;
}

point::~point(){
    cout << "Delete" << endl;
}

void Display(point& p){
    p.xVal = 5;
    p.yVal = 5;
    cout << p.xVal << ", " << p.yVal << endl;
}

point operator+(const point& p1, const point& p2){
    point p(p1.xVal + p2.xVal, p1.yVal + p2.yVal);
    return p;
}

point point::operator-(const point& p){
    point pp(this->xVal - p.xVal, this->yVal - p.yVal);
    return pp;
}

ostream& operator<<(ostream& o, const point& p){
    o << p.xVal << ", " << p.yVal << endl;
    return o;
}

istream& operator>>(istream& i, point& p){
    cout << "xVal = ";
    i >> p.xVal;
    cout << "yVal = ";
    i >> p.yVal;
    return i;
}

point::point(int value)
    :xVal(value), yVal(value)
{
}

point& point::operator++(){
    this->xVal++;
    this->yVal++;
    return (*this);
}

const point point::operator++(int){
    point before = (*this);
    this->xVal++;
    this->yVal++;
    return before;
}