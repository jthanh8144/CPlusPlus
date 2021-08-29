#include <stdio.h>
long long nhap(long long a[],long long i){
	long long tg;
	printf("Nhap so: ");
	scanf("%ld",&a[i]);
	if (a[i]!=0) return a[i]+nhap(a,i+1);
}
main(){
	long long s,a[100000],i=0;
	s=nhap(a,i);
	printf("Tong da nhap la: %ld",s);
}
