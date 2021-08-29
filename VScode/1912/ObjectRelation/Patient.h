#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Doctor;

class Patient{
    string nameP;
    vector<Doctor*> doctor;
    void addDoctor(Doctor*);
    public:
        Patient(string = NULL);
        ~Patient();
        string getName() const;
        friend ostream& operator<<(ostream&, const Patient&);
        friend class Doctor;
};