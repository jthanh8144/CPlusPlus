//#include "Patient.h"
#include "Doctor.h"

void Patient::addDoctor(Doctor *d){
    this->doctor.push_back(d);
}

Patient::Patient(string name)
    : nameP(name){

}

Patient::~Patient(){

}

string Patient::getName() const {
    return this->nameP;
}

ostream& operator<<(ostream& o, const Patient& p){
    int number = p.doctor.size();
    if (number == 0){
        o << p.nameP << " khong co bac si nao!" << endl;
    }
    else{
        o << p.nameP << " dang duoc chua boi: ";
        for (int i = 0; i < number; i++)
            o << p.doctor[i]->getName() << " ";
        o << endl;
    }
    return o;
}