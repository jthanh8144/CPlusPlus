//sinh
#include <iostream>
using namespace std;

void init(int a[], int k){
    for (int i = 1; i <= k; i++){
        a[i] = i;
    }
}

void out(int a[], int k){
    for (int i = 1; i <= k; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

int islast(int a[], int n, int k){
    for (int i = 1; i <= k; i++){
        if (a[i] != n - k + i) return 0;
    }
    return 1;
}

void gen(int a[], int n, int k){
    int i = k;
    while (a[i] == n-k+i){
        i--;
    }
    a[i] = a[i] + 1;
    for (int j = i + 1; j <= k; j++){
        a[j] = a[i] - i + j;
    }
}

void method(int a[], int n, int k){
    init(a, k);
    out(a, k);
    int stop = islast(a, n, k);
    while (stop == 0){
        gen(a, n, k);
        out(a, k);
        stop = islast(a, n, k);
    }
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    int *a = new int[n+1];
    for (int k = 1; k <= n; k++){
        method(a, n, k);
        cout << endl;
    }
    return 0;
}