#include <iostream>
#include "SinhVien.h"
//#include "Lecturer.h"
using namespace std;

class Lecturer;
class SinhVien;

template<class Type>
class LopSinhHoat{
    protected:
        string TenLSH;
        Type** pSV;
        Lecturer* GVCN;
        int SiSO;
    public:
        LopSinhHoat(string = NULL, Lecturer* = NULL, int = 0);
        ~LopSinhHoat();

        string GetLop() const;
        // void Erase(); // clear mang con tro data dang tro toi
        //LopSinhHoat<Type>& operator[](const int&); // dung cho erase
        // int getLength() const; // lay do dai mang
        // void Reallocate(); // thay doi kich thuoc mang, thuc hien nhanh
        // void Resize(); // thay doi kich thuoc mang, thuc hien cham
        // void InsertFirst();
        // void InsertLast();
        // void Insert(); // them phan tu o vi tri k
        // void Remove(); // xoa phan tu tai vi tri k
        //friend ostream& operator<<(ostream&, const LopSinhHoat<Type>&);
        //friend istream& operator>>(istream&, LopSinhHoat&);
        //LopSinhHoat<Type>& operator=(LopSinhHoat<Type>&);
};