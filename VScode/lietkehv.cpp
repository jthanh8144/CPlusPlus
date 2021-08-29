#include <iostream>
using namespace std;

void out(int b[], int n){
    for (int i = 1; i <= n; i++) cout << b[i] << " ";
    cout << endl;
}

void Try(int i, int s[], int b[], int n){
    for (int j = 1; j <= n; j++)
        if (b[j] == 1){
            s[i] = j;
            b[j] = 0;
            if (i == n) out(s, n);
                else Try(i+1, s, b, n);
            b[j] = 1;
        }
}

int main(){
    int n, *a, *b;
    cin >> n;
    a = new int [n+1];
    b = new int [n+1];
    for (int i = 1; i <= n; i++) b[i] = 1;
    Try(1, a, b, n);
    return 0;
}