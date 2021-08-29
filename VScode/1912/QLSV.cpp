#include "QLSV.h"

QLSV::QLSV(){
    this->n = 0;
    this->data = nullptr;
}

QLSV::~QLSV(){
    delete[] this->data; 
}

ostream& operator<<(ostream& o, const QLSV& db){
    o << "DSSV:" << endl;
    for (int i = 0; i < db.n; i++){
        o << *(db.data + i);
    }
    return o;
}

void QLSV::Add(const SV& s){
    if (this->n == 0){
        this->data = new SV[this->n + 1];
        this->data[this->n] = s;
    }
    else{
        SV *temp = new SV[this->n];
        for (int i = 0; i < this->n; i++){
            *(temp + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new SV[this->n +1];
        for (int i = 0; i < this->n; i++){
            *(this->data + i) = *(temp + i);
        }
        this->data[this->n] = s;
    }
    this->n++;
}


SV& QLSV::operator[](const int& index){
    static SV error = (0, 0, 0);
    return (index >= 0 && index < this->n)
        ? *(this->data + index)
        : error;
}

void QLSV::Insert(const SV& s, const int& k){
    if (k == this->n || k > this->n) Add(s);
    else if (k == 0){
        SV *temp = new SV[this->n];
        for (int i = 0; i < this->n; i++){
            *(temp + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new SV[this->n +1];
        this->data[0] = s;
        for (int i = 0; i < this->n; i++){
            *(this->data + i + 1) = *(temp + i);
        }
        this->n++;
    }
    else{
        SV *temp = new SV[this->n];
        for (int i = 0; i < this->n; i++){
            *(temp + i) = *(this->data + i);
        }
        delete[] this->data;
        this->data = new SV[this->n +1];
        for (int i = 0; i < k; i++){
            *(this->data + i) = *(temp + i);
        }
        this->data[k] = s;
        for (int i = k; i < this->n; i++){
            *(this->data + i + 1) = *(temp + i);
        }
        this->n++;
    }
}

int QLSV::IndexOf(const SV& s){
    for (int i = 0; i < this->n; i++){
        if (s == this->data[i]) return i;
    }
    return -1;
}

void QLSV::Remove(const SV& s){
    int i, k = IndexOf(s);
    if (k != -1){
        SV *temp = new SV[this->n - 1];
        if (k == this->n - 1){
            for (i = 0; i < this->n - 1; i++) *(temp + i) = *(this->data + i);
            delete[] this->data;
            this->data = new SV[this->n - 1];
            for (i = 0; i < this->n - 1; i++) *(this->data + i) = *(temp + i);
        }
        else{
            for (i = 0; i < k; i++) *(temp + i) = *(this->data + i);
            for (i = k + 1; i < this->n; i++) *(temp + i) = *(this->data + i);
            delete[] this->data;
            this->data = new SV[this->n - 1];
            for (i = 0; i < this->n-1; i++) *(this->data + i) = *(temp + i);
        }
        this->n--;
    }
    else cout << "Khong co sinh vien can xoa! " << endl;
}

void QLSV::RemoveAt(const int& k){
    if (k < 0 || k > this->n) cout << "Vi tri can xoa sai!" << endl;
    else{
        int i;
        SV *temp = new SV[this->n - 1];
        if (k == this->n - 1){
            for (i = 0; i < this->n - 1; i++) *(temp + i) = *(this->data + i);
            delete[] this->data;
            this->data = new SV[this->n - 1];
            for (i = 0; i < this->n - 1; i++) *(this->data + i) = *(temp + i);
        }
        else{
            for (i = 0; i < k; i++) *(temp + i) = *(this->data + i);
            for (i = k + 1; i < this->n; i++) *(temp + i) = *(this->data + i);
            delete[] this->data;
            this->data = new SV[this->n - 1];
            for (i = 0; i < this->n-1; i++) *(this->data + i) = *(temp + i);
        }
        this->n--;
    }
}

void QLSV::Update(const int& MSV){
    SV s;
    int k = -1;
    for (int i = 0; i < this->n; i++){
        if (MSV == (this->data + i)->getMSV()) k = i;
        break;
    }
    if (k != -1){
        RemoveAt(k);
        cin >> s;
        Insert(s, k);
    }
    else cout << "Khong co sinh vien trung voi ma sinh vien da nhap!" << endl;
}