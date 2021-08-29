#include <stdio.h>
void nhap(long a[],long n){
	for (int i=0;i<n;i++){
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(long a[],long n){
	printf("Mang da nhap la: ");
	for (int i=0;i<n;i++) 
		printf("%d ",a[i]);
	printf("\n");
}
main(){
	long a[10000],n;
	printf("Nhap n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
}
