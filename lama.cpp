#include<stdio.h>

main(){
	int n,i,k;
	printf("Nhap so nguyen n = ");
	scanf("%d",&n);
	if (n/1000 > 0){
		for (i = 0; i < n/1000; i++) printf("M");
		n %= 1000;
	}
	if (n/900 > 0){
		for (i = 0; i < n/900; i++) printf("CM");
		n %= 900;
	}
	if (n/500 > 0){
		for (i = 0; i < n/500; i++) printf("D");
		n %= 500;
	}
	if (n/400 > 0){
		for (i = 0; i < n/400; i++) printf("CD");
		n %= 400;
	}
	if (n/100 > 0){
		for (i = 0; i < n/100; i++) printf("C");
		n %= 100;
	}
	if (n/90 > 0){
		for (i = 0; i < n/90; i++) printf("XC");
		n %= 90;
	}
	if (n/50 > 0){
		for (i = 0; i < n/50; i++) printf("L");
		n %= 50;
	}
	if (n/40 > 0){
		for (i = 0; i < n/40; i++) printf("XL");
		n %= 40;
	}
	if (n/10 > 0){
		for (i = 0; i < n/10; i++) printf("X");
		n %= 10;
	}
	if (n/9 > 0){
		for (i = 0; i < n/9; i++) printf("IX");
		n %= 9;
	}
	if (n/5 > 0){
		for (i = 0; i < n/5; i++) printf("V");
		n %= 5;
	}
	if (n/4 > 0){
		for (i = 0; i < n/4; i++) printf("IV");
		n %= 4;
	}
	for (i = 0; i < n; i++){
		printf("I");
	}
}
