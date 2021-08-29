#include <stdio.h>
#include <math.h>
float tong(long x,long n){
	if (n==0) return 1;
	return tong(x,n-1)+(pow(x,n)/n);
}
main(){
	long x,n;
	printf("Nhap x, n: ");
	scanf("%d %d",&x,&n);
	printf("Tong Sn = %f",tong(x,n));
}
