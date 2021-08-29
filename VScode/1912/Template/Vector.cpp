#include "Vector.h"

template<class T>
Vector<T>::Vector(){
    cout << "Vector" << endl;
}

template<class T>
Vector<T>::Vector(int n, const T& t){
    this->size = n;
    this->data = new T[this->size];
    for (int i = 0; i < this->size; i++){
        *(this->data + i) = t;
    }
}

template<class T>
Vector<T>::~Vector(){
    delete [] this->data;
}

template<class T>
void Vector<T>::Show(){
    for(int i = 0; i < this->size; i++)
        cout << *(this->data + i) << " ";
    cout << endl;
}