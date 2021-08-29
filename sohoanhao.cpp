#include <stdio.h>

main(){
	long n,kt=0,i;
	printf("Nhap so can kiem tra n = ");
	scanf("%d",&n);
	for (i=1;i<n;i++)
		if (n%i==0) kt+=i;
	if (kt==n) printf("%d la so hoan hao",n);
	else printf("%d khong phai la so hoan hao",n);
}
