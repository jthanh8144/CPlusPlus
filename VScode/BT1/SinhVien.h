#include <iostream>
#include <string>
#include "Person.h"
using namespace std;

template<class Type>
class LopSinhHoat;

class SinhVien : public Person{
    protected:
        string MSV;
        LopSinhHoat<SinhVien>* Lop;
        double DTB;
        void AddLSH(LopSinhHoat<SinhVien>*);
    public:
        SinhVien(string = NULL, LopSinhHoat<SinhVien>* = nullptr, double = 0);
        ~SinhVien();

        string getNameS() const;
        friend istream& operator>>(istream&, SinhVien&);
};