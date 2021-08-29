#include <stdio.h>
unsigned long gtk(long n){
	if (n<2) return 1;
	return n*gtk(n-2);
}
main(){
	long n;
	printf("Nhap n = ");
	scanf("%d",&n);
	printf("%d",gtk(n));
}
