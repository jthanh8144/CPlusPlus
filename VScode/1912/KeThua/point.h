#include <iostream>
using namespace std;

class point{
    protected:
        int xVal;
        int yVal;
    public:
        point(int, int);
        virtual ~point();
        friend ostream& operator<<(ostream& , const point& );
        virtual void show();
};