#include <iostream>
#include <string>
#include <exception>
#include "CVector.h"

using namespace std;

class Person{
    protected:
        string Ten;
        int Tuoi;
        string DiaChi;
        bool GioiTinh;
    public:
        Person(string = NULL, int = 0, string = NULL, bool = true);
        ~Person();

        string getTen();
        int getTuoi();
        string getDiaChi();
        bool getGioiTinh();
        //void Show();
};