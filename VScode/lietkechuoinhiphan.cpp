#include <iostream>
using namespace std;

void out(int b[], int n){
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << endl;
}

void Try(int i, int b[], int n){
    for (int j = 0; j <= 10; j++){
        if (j == 1 || j == 0){
            b[i] = j;
            if (i == n) out(b, n);
            else Try(i+1, b, n);
        }
    }
}

int main(){
    int n, *b;
    cin >> n;
    b = new int [n+1];
    Try(1, b, n);
    return 0;
}