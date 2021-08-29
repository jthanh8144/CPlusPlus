#include <stdio.h>
void nhap(long a[],long n){
	for (int i=0;i<n;i++){
		printf("A[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(long a[],long n){
	for (int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}
void xoa(long a[],long n){
	for (int i=0;i<n;i++) a[i]=a[i+1];
	xuat(a,n-1);
}
main(){
	long a[100000],n;
	printf("Nhap n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	xoa(a,n);
}
