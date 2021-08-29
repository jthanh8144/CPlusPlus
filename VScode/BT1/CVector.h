#include <iostream>
using namespace std;

template <class T>
class CVector{
    T* data;
    int size;
    public:
        CVector();
        ~CVector();
        int GetSize();
        void Add(const T&);
        int IndexOf(const T&);
        void Delete(const T&);
        T& GetData(const int&);
        //void AddAt(const T&, const int&);
        //void DeleteAt();
        //void Show();
};