#include <iostream>
using namespace std;
class SV{
    private: 
        int MSSV;
        int Age;
        double DTB;
    public:
        SV(int = 1, int = 1, double = 0.1);
        ~SV();
        int& getMSV();
        int operator()(const int&);
        friend ostream& operator<<(ostream&, const SV&);
        friend bool operator==(const SV&, const SV&);
        friend istream& operator>>(istream&, SV&);
};