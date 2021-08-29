#include <stdio.h>
main(){
	long a[100000],i,n;
	printf("Nhap n = ");
	scanf("%d",&n);
	a[0]=1;
	a[1]=1;
	printf("%d %d ",a[0],a[1]);
	i=1;
	while (a[i]<n){
		a[i+1]=a[i]+a[i-1];
		if (a[i+1]>n) break;
		i+=1;
		printf("%d ",a[i]);
	}
}
