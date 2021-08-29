#include <stdio.h>
void nhap(int a[],int n){
	for (int i=1;i<=n;i++){
		printf("Nhap phan tu thu %d cua mang: ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(int a[],int n){
	for (int i=1;i<=n;i++)
		printf("\n Phan tu thu %d cua mang la: %d",i,a[i]);
}
main(){
	int n,a[10000];
	printf("Nhap so phan tu cua mang n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
}
