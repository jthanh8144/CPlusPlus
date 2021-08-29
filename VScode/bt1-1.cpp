// quay lui
#include <iostream>
using namespace std;

void out(int a[], int k){
    for (int i = 1; i <= k; i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

void Try(int a[], int n, int k, int i){
    for (int j = a[i-1] + 1; j <= n-k+i; j++){
        a[i] = j;
        if(i == k){
            out(a, k);
        }
        else{
            Try(a, n, k, i+1);
        }
    }
}

int main(){
    int n;
    cout << "n = ";
    cin >> n;
    int *a = new int[n + 1];
    for (int k = 1; k <= n; k++){
        a[0] = 0;
        Try(a, n, k, 1);
        cout << endl;
    }
    return 0;
}