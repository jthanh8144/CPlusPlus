#include <iostream>
#include <conio.h>
#include "Department.h"
using namespace std;

int main(){
    //Teacher *t = new Teacher("NVA", 40);
    Teacher **t = nullptr;
    *(t + 0) = new Teacher("T1", 25);
    *(t + 1) = new Teacher("T2", 15);
    //Teacher *t;
    Department d("CNTT", t);
    //Department d("CNTT", *(t + 1));
    cout << d;
    //cout << d.Dsize();
    // {
    //     Department d("CNTT", t);
    //     cout << d;
    // }
    
    delete t;
    return 0;
}