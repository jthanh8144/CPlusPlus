#include <stdio.h>
void nhap(long a[],long *n){
	for (long i=0;i<*n;i++){
		printf("Nhap phan tu thu %d cua mang: ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(long a[],long *n){
	for (int i=0;i<*n;i++)
		printf("%d ",a[i]);
}
int shh(long a){
	long i,kt=0;
	if (a == 2) return 0;
	for (i=1;i<a;i++)
		if (a%i==0) kt+=i;
	if (a==kt) return 1;
	else return 0;
}
void xoa(long a[],long *n,long k){
	if (k<*n){
		for (int i=k;i<*n-1;i++) a[i]=a[i+1];
		(*n)--;
	}
}
void kt(long a[],long *n){
	long i;
	for (i=0;i<*n;i++)
		if (shh(a[i]) == 1){
			xoa(a,n,i);
			i--;
		} 
}
main(){
	long n,a[100000],k=0;
	printf("Nhap so phan tu cua mang n = ");
	scanf("%d",&n);
	nhap(a,&n);
	xuat(a,&n);
	printf("\n");
	kt(a,&n);
	xuat(a,&n);
}
