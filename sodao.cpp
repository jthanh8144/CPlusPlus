#include<stdio.h>

main(){
	int n,m;
	printf("Nhap so nguyen n = ");
	scanf("%d",&n);	
	while (n/10 != 0){
		m = m*10 + (n%10);
		n/=10;
	}
	m = m*10 + n;
	printf("So dao cua %d la ",m);
}
