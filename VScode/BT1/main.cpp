#include <iostream>
#include "Lecturer.h"
using namespace std;

int main(){
    Lecturer *l = new Lecturer("Vo Van Thanh", 19, "Quang Nam", true, "A", "GV");
    cout << "Nhap lec" << endl;
    cin >> *l;
    cout << "Xuat lec" << endl;
    cout << *l;
    
    return 0;
}