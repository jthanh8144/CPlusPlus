#include <stdio.h>
void dao(long n){
	int a[100000],m,i=0;
	while (n/10!=0){
		a[i]=n%10;
		i+=1;
		n/=10;
	}
	a[i]=n;
	m=i+1;
	for(i=0;i<m;i++) printf("%d",a[i]);
}
main(){
	long n;
	printf("Nhap n = ");
	scanf("%d",&n);
	printf("so dao cua %d la: ",n);
	dao(n);
}
