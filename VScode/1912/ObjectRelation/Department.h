#include "Teacher.h"
class Department{
    Teacher **teacher;
    string nameDep;
    public:
        Department(string = "", Teacher** = nullptr);
        ~Department();
        int Dsize() const;
        friend ostream& operator<<(ostream&, const Department&);
};