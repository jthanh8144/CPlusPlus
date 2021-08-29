#include <iostream>
using namespace std;

int main(){
	int loaitien[] = {50, 20, 10, 5, 2, 1}, x, n;
	cout << "Nhap so tien x = "; cin >> x;
	for (int i = 0; i < 6; i++){
		n = x / loaitien[i];
		cout << n << " to " << loaitien[i] << endl;
		x %= loaitien[i];
	}
	return 0;
}
