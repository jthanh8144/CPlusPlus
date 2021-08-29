#include <stdio.h>
main(){
	int n,i;
	float s=0;
	printf("Nhap so nguyen duong n = ");
	scanf("%d",&n);
	for (i=1;i<=n;i++) s+=1.0/i;
	printf("Ket qua: %0.2f",s);
}
