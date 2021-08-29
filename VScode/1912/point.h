#include <iostream>
using namespace std;

class point{
    private:
        int xVal;
        int yVal;
    public:
        static int n;
    public:
        point();
        point(int, int);
        point(const point&);
        point(int);
        ~point();
        int Get_xVal();
        void Set_xVal(int);
        void tt(int);
        void show();
        friend void Display(point&);
        static void PrintCount();
        friend point operator+(const point&, const point&);
        point operator-(const point&);
        friend ostream& operator<<(ostream& , const point& );
        friend istream& operator>>(istream& , point&);
        point& operator++();
        const point operator++(int);
};