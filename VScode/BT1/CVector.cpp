#include "CVector.h"

template <class T>
CVector<T>::CVector(){
    this->size = 0;
    this->data = nullptr;
}

template <class T>
CVector<T>::~CVector(){
    delete [] this->data;
}

template <class T>
int CVector<T>::GetSize(){
    return this->size;
}

template <class T>
void CVector<T>::Add(const T& data){
    if (this->size == 0){
        this->data = new T[this->size + 1];
        this->data[this->size] = data;
    }
    else{
        T *temp = new T[this->size];
        for (int i = 0; i < this->size; i++){
            *(temp + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new T[this->size + 1];
        for (int i = 0; i < this->size; i++){
            *(this->data + i) = *(temp + i);
        }
        this->data[this->size] = data;
    }
    this->size++;
}

template <class T>
int CVector<T>::IndexOf(const T& data){
    for (int i = 0; i < this->size; i++){
        if (data == this->data[i]) return i;
    }
    return -1;
}

template <class T>
void CVector<T>::Delete(const T& data){
    int i, k = IndexOf(data);
    if (k != -1){
        T *temp = new T[this->size - 1];
        if (k == this->size - 1){
            for (i = 0; i < this->size - 1; i++) *(temp + i) = *(this->data + i);
            delete[] this->data;
            this->data = new T[this->size - 1];
            for (i = 0; i < this->size - 1; i++) *(this->data + i) = *(temp + i);
        }
        else{
            for (i = 0; i < k; i++) *(temp + i) = *(this->data + i);
            for (i = k + 1; i < this->size; i++) *(temp + i) = *(this->data + i);
            delete[] this->data;
            this->data = new T[this->size - 1];
            for (i = 0; i < this->size - 1; i++) *(this->data + i) = *(temp + i);
        }
        this->size--;
    }
    else cout << "Error! " << endl;
}

template <class T>
T& CVector<T>::GetData(const int& index){
    return *(this->data + index);
}

// template <class T>
// void CVector<T>::AddAt(const T& data, const int& index){
//     if (index == this->size || index > this->size)
// }
