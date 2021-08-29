#include <stdio.h>
void nhap(long a[],long n){
	for (int i=0;i<n;i++){
		printf("A[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(long a[],long n){
	for (int i=0;i<n;i++) printf("%d ",a[i]);
}
int snt(long n){
	long i;
	if (n<2) return 0;
	for (i=2;i*i<=n;i++)
		if (n%i==0) return 0;
	return 1;
}
void tong(long a[],long n){
	long s=0;
	for (int i=0;i<n;i++)
		if (snt(a[i]) == 1) s+=a[i];
	printf("Tong cac so nguyen to la: S = %d",s);
}
main(){
	long a[100000],n;
	printf("Nhap so phan tu n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	tong(a,n);
}
