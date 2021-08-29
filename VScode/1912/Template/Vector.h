#include <iostream>

using namespace std;

template<class T>
class Vector{
    T* data;
    int size;
public:
    Vector();
    Vector(int, const T&);
    ~Vector();
    void Show();
};