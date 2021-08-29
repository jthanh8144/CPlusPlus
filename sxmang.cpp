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
void sx(int a[],int n){
	int i,j;
	for (i=0;i<n-1;i++)
		for (j=i+1;j<n;j++)
			if (a[i]>a[j]){
				int tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			}
	for (i=0;i<n;i++) printf("%d ",a[i]);
}
main(){
	int a[10000],n;
	printf("Nhap n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	sx(a,n);
}
