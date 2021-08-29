#include "Doctor.h"

int main(){
    Patient *p1 = new Patient("Thanh");
    Patient *p2 = new Patient("Thinh");
    Patient *p3 = new Patient("Vy");
    Doctor *d1 = new Doctor("Tuong");
    Doctor *d2 = new Doctor("Phuong");
    d1->addPatient(p1);
    d2->addPatient(p1);
    d2->addPatient(p3);
    cout << *d1; cout << *d2;
    cout << *p1; cout << *p2; cout << *p3;
    delete p1; delete p2; delete p3;
    delete d1; delete d2;
    return 0;
}