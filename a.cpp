#include <iostream>
using namespace std;

int tich(int a[], int n){
	if (n == 0) return 1;
	else{
		if (a[n] % 2 == 1) return tich(a, n-1)*a[n];
		else return tich(a, n-1);
	}
}

int main(){
	int a[] = {0, 3, 3, 3, 5, 5, 8, 7};
	cout << 1*5*5*3*7*3*3;
	cout << tich(a, 7);
	return 0;
}
