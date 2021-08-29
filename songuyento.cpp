#include <stdio.h>
int kt(int n){
	int i;
	if (n<2) return 0;
	for (i=2;i*i<=n;i++)
		if (n%i==0) return 0;
	return 1;
}
int main(){
	int n,i;
	printf("Nhap n = ");
	scanf("%d",&n);
	if (kt(n)==1) printf("%d la so nguyen to \n",n);
	else printf("%d khong phai la so nguyen to \n",n);
	i=1;
	while (i<=n){
		if (kt(i)==1) printf("%d ",i);
		i++;
	}
}
