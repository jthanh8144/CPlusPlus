#include <stdio.h>
#include <math.h>
void nhap(long a[], long n){
	for (int i=0;i<n;i++){
		printf("A[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(long a[], long n){
	for (int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}
int scp(long a){
	double tg,n;
	tg=double(a);
	n=sqrt(tg);
	if (n == long(n)) return 1;
	return 0;
}
void kt(long a[], long n){
	long s=0;
	for (int i=0;i<n;i++)
		if (scp(a[i]) == 1) {
			printf("%d ",a[i]);
			s+=a[i];
		}
	printf("\nTong cac so chinh phuong trong mang la: %d",s);
}
main(){
	long a[100000],n;
	printf("Nhap n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	kt(a,n);
}
