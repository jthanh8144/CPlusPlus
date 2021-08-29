#include <stdio.h>
int fibo(long n){
	long a[100000],i=1,j;
	a[0]=0;
	a[1]=1;	
	while (a[i]<=n){
		a[i+1]=a[i]+a[i-1];
		i+=1;
	}
	for (j=0;j<=i;j++) if (a[j]==n) return 1;
}
main(){
	long n;
	printf("Nhap n = ");
	scanf("%d",&n);
	if (fibo(n)==1) printf("%d la so thuoc day fibonacci.",n);
	else printf("%d la so khong thuoc day fibonacci.",n);
}
