#include <iostream>
using namespace std;

class Matrix{
    private:
        int** data;
        int row, col;
    public:
        Matrix(int = 4, int = 3, int = 0);
        ~Matrix();
        void show();
        friend ostream& operator<<(ostream&, const Matrix&);
        friend istream& operator>>(istream&, Matrix&);
        int& operator()(const int&, const int&); 
};