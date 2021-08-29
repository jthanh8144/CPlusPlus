#include <iostream>
using namespace std;

int count = 1;

void out(int x[], int n){
    cout << ::count << ": ";
    for (int i = 1; i<=n; i++) cout << x[i] << " ";
    cout << endl;
    ::count++;
}

void Try(int i, int x[], int n,int a[], int b[], int c[])
{
    for (int j = 1; j<=n; j++) {
        if (a[j]==1 && b[i+j]==1 && c[i-j]==1) {
            x[i] = j;
            a[j] = 0;
            b[i+j] = 0;
            c[i-j] = 0;
            if (i==n) out(x,n);
                else Try(i+1,x,n,a,b,c);
            a[j] = 1;
            b[i+j] = 1;
            c[i-j] = 1;
                
        }
    }
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int a[101];
    int b[101];
    int c[101];
    int *x = new int[n+1];

    // buoc khoi tao
    for (int i = 1; i<=n; i++) a[i] = 1;
    for (int i = 2; i<=2*n; i++) b[i] = 1;
    for (int i = 1-n; i<=n-1; i++) c[i] = 1;
    Try(1,x,n, a,b,c);
    return 0;
}