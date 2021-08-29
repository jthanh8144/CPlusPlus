#include "LopSinhHoat.h"
//#include "SinhVien.h"

template<class Type>
LopSinhHoat<Type>::LopSinhHoat(string TL, Lecturer* L, int SS)
    : TenLSH(TL), GVCN(L), SiSO(SS){

}

template<class Type>
LopSinhHoat<Type>::~LopSinhHoat(){
    delete [] this->pSV;
}

template<class Type>
string LopSinhHoat<Type>::GetLop() const{
    return this->TenLSH;
}


template<class Type>
bool LopSinhHoat<Type>::FindLSH(LopSinhHoat<Type> *List, string Lop){
    
    return true;
}

// template<class Type>
// ostream& operator<<(ostream& o, const LopSinhHoat<Type>& lop){
//     o << "Ten lop: " << lop.TenLSH << endl
//         << "Danh sach SV: " << lop.pSV << endl
//         << "Giao vien chu nhiem: " << lop.GVCN << endl
//         << "Si so: " << lop.SiSO << endl;
//     return o;
// }

