#include <stdio.h>
#include <math.h>
long long gt(long n){
	long long i,tg=1;
	if (n==0||n==1) return 1;
	for (i=1;i<=n;i++) tg*=i;
	return tg;
}
main(){
	double s=0,x;
	long n=0;
	printf("Nhap x (rad) = ");
	scanf("%lf",&x);
	while (fabs(pow(x,2*n)/gt(2*n)) >= pow(10,-6)){
		s+=pow(-1,n)*(pow(x,2*n)/gt(2*n));
		n+=1;
	}
	printf("S = cos(%.2lf) = %lf",x,s);
}
