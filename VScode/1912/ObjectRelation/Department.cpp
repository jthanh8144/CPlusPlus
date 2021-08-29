#include "Department.h"

Department::Department(string name, Teacher **teacher)
    : nameDep(name), teacher(teacher){

}

Department::~Department(){
    
}

// int Department::Dsize() const{
//     if (this->teacher == nullptr) return 0;
//     else{
//         this->teacher;
//     }
// }

ostream& operator<<(ostream &o, const Department& d){
    // if (d.Dsize() == 0) o << "Khong co giao vien nao thuoc khoa!" << endl;
    // else {
    //     o << "Khoa " << d.nameDep << ": " << endl;
    //     for (int i = 0; i < d.Dsize(); i++)
    //         o << "Ten GV: " << d.teacher[i] << endl;
    // }
    o << "Khoa " << d.nameDep << ": " << endl;
    // for (int i = 0; i < 2; i++)
    //     o << "Ten GV: " << d.teacher[i] << endl;
    return o;
}