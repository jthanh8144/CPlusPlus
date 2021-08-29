#include "Matrix.h"

Matrix::Matrix(int row, int col, int value){
    if (row > 0 && col > 0){
        this->row = row;
        this->col = col;
        this->data = new int* [this->row];
        for (int i = 0; i < this->row; i++){
            *(this->data + i) = new int [this->col];
            for (int j = 0; j < this->col; j++){
                *(*(this->data +i) + j) = value;
            }
        }
    }
}

Matrix::~Matrix(){
    for (int i = 0; i < this->row; i++)
        delete [] *(this->data + i);
    delete[] this->data;
}

void Matrix::show(){
    cout << "show:" << endl;
    for(int i = 0; i < this->row; i++){
        for(int j = 0; j < this->col; j++){
            //cout << *(*(this->data +i) + j) << " ";
            cout << (*this)(i, j) << " ";
        }
        cout << endl;
    }
}

ostream& operator<<(ostream& o, const Matrix& m){
    cout << "Matrix: " << endl;
    for (int i = 0; i < m.row; i++){
        for (int j = 0; j < m.col; j++){
            o << *(*(m.data + i) + j) << " ";
        }
        cout << endl;
    }
    return o;
}

istream& operator>>(istream& inp, Matrix& m){
    for (int i = 0; i < m.row; i++){
        cout << "Nhap Matrix: " << endl;
        for (int j = 0; j < m.col; j++){
            cout << "m(" << i << ", " << j << ") = ";
            inp >> m(i, j);
        }
    }
    return inp;
}

int& Matrix::operator()(const int& row, const int& col){
    static int error = -100;
    return (row >= 0 && row < this->row && col >=0 && col < this->col ? *(*(this->data + row) + col) : error);
}

