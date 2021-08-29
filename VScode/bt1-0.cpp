#include <iostream>
using namespace std;

void out(int a[], int n){
    for (int i = 1; i <= n; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int a[], int n, int k, int i){
    for (int j = 0; j <= k; j++){
        a[i] = j;
        if (i == n){
            if (k - j == 0) out(a, n);
        }
        else{
            Try(a, n, k-j, i+1);
        }
    }
}

int main(){
    int n, k;
    cout << "n = ";
    cin >> n;
    cout << "k = ";
    cin >> k;
    int *a = new int[n+1];
    Try(a, n, k, 1);
    return 0;
}