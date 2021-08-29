#include <stdio.h>
main(){
	int n,k;
	float T=1000000;
	printf("Nhap n = ");
	scanf("%d",&n);
	for (k=0;k<n;k++) T=1.02*T;
	printf("So tien can phai tra sau %d thang la %0.3f",n,T);
}
