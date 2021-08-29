#include "Person.h"

Person::Person(string Ten, int Tuoi, string DiaChi, bool GioiTinh)
    : Ten(Ten), Tuoi(Tuoi), DiaChi(DiaChi), GioiTinh(GioiTinh) {

}

Person::~Person(){
    
}

string Person::getTen(){
    return this->Ten;
}

int Person::getTuoi(){
    return this->Tuoi;
}

string Person::getDiaChi(){
    return this->DiaChi;
}

bool Person::getGioiTinh(){
    return this->GioiTinh;
}

// istream& operator>>(istream& i, Person& p){
//     cout << "Ten: ";
//     i >> p.Ten;
//     cout << "Tuoi: ";
//     i >> p.Tuoi;
//     cout << "Dia chi: ";
//     i >> p.DiaChi;
//     string GT;
//     cout << "Gioi tinh: ";
//     i >> GT;
//     if (GT == "Nam" || GT == "nam") p.GioiTinh = true;
//     if (GT == "Nu" || GT == "nu") p.GioiTinh = false;
//     return i;
// }