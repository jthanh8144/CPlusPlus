#include <iostream>
#include "Person.h"
using namespace std;

class Lecturer : public Person{
    protected:
        string MaLecturer;
        string CapBac;
    public:
        Lecturer(string = "", int = 0, string = "", bool = true, string = "", string = "");
        Lecturer(const Lecturer&);
        ~Lecturer();

        
        string setML(string);
        string getNameL() const;
        friend ostream& operator<<(ostream&, const Lecturer&);
        friend istream& operator>>(istream&, Lecturer&);
};