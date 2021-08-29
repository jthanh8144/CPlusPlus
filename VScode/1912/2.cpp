#include "Vector.h"
#include <iostream>
using namespace std;

int main(){
    /*Vector v1;
    v1.show();
    //cout << v1;
    //cout << v1[1];*/
    Vector v1(4, 2);
    Vector v2(v1);
    Vector v3 = v1;
    Vector v4;
    v4 = v1;
    return 0;
}