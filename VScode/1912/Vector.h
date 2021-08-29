#include <iostream>
using namespace std;

class Vector{
    private:
        int *data;
        int size;
    public:
        Vector(int = 2, int = 1);
        
        ~Vector();
        void show();
        friend ostream& operator<<(ostream&, const Vector&);
        int& operator[](const int&);
        Vector(const Vector&);
        const Vector& operator=(const Vector&);
};