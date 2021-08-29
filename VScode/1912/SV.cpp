#include "SV.h"

SV::SV(int MSSV, int Age, double DTB)
    : MSSV(MSSV), Age(Age), DTB(DTB){

}

SV::~SV(){
}

int& SV::getMSV(){
    return this->MSSV;
}

ostream& operator<<(ostream& o, const SV& s){
    o << "MSSV = " << s.MSSV
        << " Age = " << s.Age
        << " DTB = " << s.DTB
        << endl;
    return o;
}

bool operator==(const SV& s1, const SV& s2){
    if (s1.MSSV == s2.MSSV && s1.Age == s2.Age && s1.DTB == s2.DTB) return true;
    else return false;
}

istream& operator>>(istream& i, SV& s){
    cout << "MSSV = ";
    i >> s.MSSV;
    cout << "Age = ";
    i >> s.Age;
    cout << "DTB = ";
    i >> s.DTB;
    return i;
}