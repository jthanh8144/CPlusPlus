#include "TG.h"
#include <iostream>
using namespace std;

TG::TG(int xa, int ya, int xb, int yb, int xc, int yc)
    : a(xa, ya), b(xb, yb), c(xc, yc)
{
    cout << "Dung TG" << endl;
}

TG::~TG(){
    cout << "Huy TG" << endl;
}

void TG::Show(){
    (this->a).show();
    (this->b).show();
    (this->c).show();
}