#include <stdio.h>
long long gtk(long n){
	long long tg=1;
	if (n==1 || n==2) return 1;
	return tg=n*gtk(n-2);
}
main(){
	long n;
	long long s;
	printf("Nhap n = ");
	scanf("%d",&n);
	s=gtk(n);
	printf("%d!! = %ld",n,s);
}
