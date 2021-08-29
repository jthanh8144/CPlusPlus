#include <stdio.h>
#include <math.h>
long long gt(long n){
	long long tg=1,i;
	if (n==1||n==0) return tg;
	for(i=1;i<=n;i++) tg*=i;
	return tg;
/*	if (n==1||n==0) return 1;
	return n*gt(n-1);*/
}
main(){
	double x,s=0;
	long n=0;
	printf("Nhap x: ");
	scanf("%lf",&x);
	while (fabs(pow(x,2*n)/gt(2*n)) >= pow(10,-6)){
		s+=pow(x,2*n)/gt(2*n);
		n++;
	
	}
	printf("S = ch(%0.2lf) = %lf",x,s);
}
