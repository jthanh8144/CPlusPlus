#include "point.h"

class point3D : public point{
    private:
        int zVal;
    public:
        point3D(int = 1, int = 2, int = 3);
        ~point3D();
        friend ostream& operator<<(ostream& , const point3D& );
        void show3D();
        void show();
};