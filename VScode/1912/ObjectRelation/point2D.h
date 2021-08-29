#include <iostream>
using namespace std;

class point2D{
    private:
        int xVal;
        int yVal;
    public:
        point2D(int = 1, int = 2);
        ~point2D();
        void setPoint(int, int);
        friend ostream& operator<<(ostream&, const point2D&);
};