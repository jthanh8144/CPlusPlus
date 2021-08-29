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
void kt(long a[],long n){
	long b[100000],i,j=0,m,tg;
	for (i=0;i<n;i++) 
		if (a[i]%2==1){
			b[j]=a[i];
			j+=1;
		}
	m=j+1;
	tg=b[0];
	for (j=1;j<m;j++)
		if (b[j]>tg) tg=b[j];
	printf("\nSo nguyen duong le lon nhat la: %d",tg);
}
main(){
	long a[100000],n;
	printf("Nhap n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	kt(a,n);
}
