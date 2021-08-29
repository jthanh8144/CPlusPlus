#include <iostream>
using namespace std;

/* Hoan vi tapX =  {1,...,n} ==> n!
n = 4
1 2 3 4 ==>ch dau tien < init(int b[], int n)
1 2 4 3
1 3 2 4
1 3 4 2
1 4 2 3
1 4 3 2
2 1 3 4
2 1 4 3
2 3 1 4
2 3 4 1
2 4 1 3
2 4 3 1
3 1 2 4
3 1 4 2
3 2 1 4
3 2 4 1
3 4 1 2
3 4 2 1
4 1 2 3
4 1 3 2
4 2 1 3
4 2 3 1
4 3 1 2
4 3 2 1 ==> cuoi cung islast(int b[], int n)
 step 1: right ->left, find j: a[j]<a[j+1]
 step 2: right -> left, find k: a[k]>a[j]
 step 3: swap(a[j], a[k])
 step 4: lat nguoc doan aj+1 den an
*/

int count = 0;

void init(int b[], int n){
    for ( int i =1; i<=n; i++) b[i] = i;
}

void out(int b[], int n){
	cout << ++count << ": ";
    for (int i =1; i<=n; i++) cout << b[i] << " ";
	cout << endl;
}

int islast(int b[], int n){
    for (int i = 1; i<=n-1; i++) 
        if(b[i]<b[i+1]) return 0;
    return 1;
}

void gen(int b[], int n){
    //step 1
    int j = n-1;
    while (b[j] > b[j+1]) j--;
    //step 2
    int k = n;
    while(b[k] < b[j]) k--;
    // step 3
    int t = b[j];
    b[j] = b[k];
    b[k] = t;
    // step 4
    int l = j+1, r = n;
    while (l<=r) {
        int t = b[l];
        b[l] = b[r];
        b[r] = t;
        l++;
        r--;
	}
}

void method(int b[], int n){
    init(b,n);
    out(b,n);
    int stop = islast(b,n);
    while (stop == 0) {
        gen(b,n);
        out(b,n);
        stop = islast(b,n);
    }
}

int main(){
	int n;
	cout << "n = ";
	cin >> n;
	int b[n+1];
	method(b, n);
	return 0;
}
