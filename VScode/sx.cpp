#include <iostream>
using namespace std;

void inp(int *p, int n){
    for (int i = 0; i < n; i++) cin >> *(p+i);
}

void out(int *p, int n){
    for (int i = 0; i < n; i++) cout << *(p+i) << " ";
    cout << endl;
}

bool lon(int a, int b){
    return (a > b) ? true : false;
}

bool be(int a, int b){
    return (a < b) ? true : false;
}

void swap(int &a, int &b){
    int t = a;
    a = b;
    b = t;
}

void sx(int *p, int n, bool (*x)(int a, int b)){
    for (int i = 0; i < n-1; i++)
        for (int j = i+1; j < n; j++)
            if (x(*(p+i), *(p+j))) swap(*(p+i), *(p+j));
}
int main(){
    int n;
    cin >> n;
    int *a = new int[n];
    inp(a, n);
    out(a, n);
    sx(a, n, be);
    out(a, n);
}