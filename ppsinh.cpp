#include <stdio.h>
#include <conio.h>

void init(int b[], int n){
	for (int i = 1; i <= n; i++) b[i] = 0;
}

void out(int b[], int n){
	for (int i = 1; i <= n; i++) printf("%d ", b[i]);
	printf("\n");
}

void gen(int b[], int n){
	int i = n;
	while (b[i] == 1) b[i--] = 0;
	b[i] = 1;
}

int kt(int b[], int n){
	for (int i = 1; i <= n; i++)
		if (b[i] == 0) return 0;
	return 1;
}

void method(int b[], int n){
	init(b, n);
	out(b, n);
	int stop = kt(b, n);
	while (stop == 0){
		gen(b, n);
		out(b, n);
		stop = kt(b, n);
	}
}

main(){
	int n;
	printf("Nhap n = ");
	scanf("%d", &n);
	int b[n];
	method(b, n);
}
