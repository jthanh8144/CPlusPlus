#include <stdio.h>
int sodoixung(long n){
	long a[100000],i=0,tg=0,m;
	while (n/10!=0){
		a[i]=n%10;
		i+=1;
		n/=10;
	}
	a[i]=n;
	m=i+1;
	for (i=0;i<m/2;i++)
		if (a[i]==a[m-i-1]) tg+=1;
	if (tg==m/2) return 1;
	return 0;
}
main(){
	long n,i;
	printf("Nhap n = ");
	scanf("%d",&n);
	for (i=0;i<n;i++)
		if (sodoixung(i)==1) printf("%d ",i);
}
