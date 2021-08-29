#include <iostream>
using namespace std;

char x[] = "abc", y[] = "de", z[] = "mnt";

void out(int i, int j, int k){
    cout << x[i] << " " << y[j] << " " << z[k] << endl;
}

int kt(int i, int j, int k){
    if (i == 2 && j == 1 && k == 2) return 1;
    return 0;
}

void gen(int &i, int &j, int &k){
    if (k != 2) k++;
    else{
        k = 0;
        if (j != 1) j++;
        else{
            j = 0;
            i++;
        }
    }
}

void method(){
    int i = 0, j = 0, k = 0;
    out(i, j, k);
    int stop = kt(i, j, k);
    while (stop == 0){
        gen(i, j, k);
        out(i, j, k);
        stop = kt(i, j, k);
    }
}

int main(){
    method();
    return 0;
}