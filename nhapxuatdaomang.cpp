#include <stdio.h>
void nhap(int a[],int n){
	for (int i=0;i<n;i++){
		printf("Nhap phan tu thu %d cua mang: ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(int a[],int n){
	for (int i=0;i<n;i++) printf("Phan tu thu %d cua mang la: %d\n",i,a[i]);
}
void dao(int a[],int n){
	int tg;
	for (int i=0;i<n/2;i++){
		tg=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=tg;
	}
	for (int i=0;i<n;i++) printf("%d ",a[i]);
}
main(){
	int a[10000],n;
	printf("Nhap so phan tu cua mang n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	dao(a,n);
}
