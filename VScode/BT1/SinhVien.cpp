//#include "SinhVien.h"
#include "LopSinhHoat.h"

void SinhVien::AddLSH(LopSinhHoat<SinhVien>* l){
    
}

SinhVien::SinhVien(string MSV, LopSinhHoat<SinhVien>* Lop, double DTB)
    : MSV(MSV), Lop(Lop), DTB(DTB){

}

SinhVien::~SinhVien(){
    
}

string SinhVien::getNameS() const{
    return this->Ten;
}

// istream& operator>>(istream& i, SinhVien& sv){
//     cout << "Nhap sinh vien: " << endl;
//     cout << "\tTen: ";
//     i >> sv.Ten;
//     cout << "\tTuoi: ";
//     i >> sv.Tuoi;
//     if (sv.Tuoi < 0) throw false;
//     cout << "\tDia chi: ";
//     i >> sv.DiaChi;
//     string GT;
//     cout << "\tGioi tinh: ";
//     i >> GT;
//     if (GT == "Nam" || GT == "nam") sv.GioiTinh = true;
//     else if (GT == "Nu" || GT == "nu") sv.GioiTinh = false;
//         else throw -1;
//     cout << "\tMa sinh vien: ";
//     i >> sv.MSV;
//     if (sv.MSV[0] = "0" || sv.MSV.length() > 10) throw string("Ma sinh vien gom 10 ki tu va khong bat dau bang \"0\"!");
//     cout << "\tLop: ";
//     //i >> sv.Lop.TenLSH; //sai o day ne`
//     //xu li them sinh vien vao lop sinh hoat
//     cout << "\tDiem trung binh: ";
//     i >> sv.DTB;
//     if (sv.DTB < 0 && sv.DTB > 4) throw -10.01;
//     return i;
// }

