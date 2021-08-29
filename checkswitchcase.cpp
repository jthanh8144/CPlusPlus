#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int check_cp(float inpt){
	if (inpt != (int)inpt) return 0;
	char ipt[100];
	sprintf(ipt, "%.0f", inpt);
	if (strcmp(ipt, "0") == 0) return -1;
	else if (strcmp(ipt, "-1") == 0) return 0;
	int temp = atoi(ipt);
	if (temp - 1 < 0) return 0;
	return temp;
}

int main(){
	float choice;
	cout << "Nhap lua chon: ";
	cin >> choice;
	switch(check_cp(choice)){
		case 1:
			cout << "1" << endl;
			break;
		case 2:
			cout << "2" << endl;
		default:
			cout << "error" << endl;		
	}
	return 0;
}
