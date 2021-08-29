#include <stdio.h>
void nhap(long a[],long n){
	for (long i=0;i<n;i++){
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(long a[],long n){
	for (int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}
void xoa(long a[],long n){
	long i,k;
	for (i=0;i<n;i++)
		if (a[i]<0){
			for (k=i;k<n;k++) a[k]=a[k+1];
			n--;i--;	
		}
}
main(){
	long a[100000],n;
	printf("Nhap n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	xoa(a,n);
	xuat(a,n);
}
