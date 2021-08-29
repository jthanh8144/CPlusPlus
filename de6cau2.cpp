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
void xoa(long a[],long n,long k){
	int i,j;
	for (i=0;i<n;i++){
		if (i==k) {
			for (j=k;j<n;j++) a[j]=a[j+1];
			n--;
		}
		printf("%d ",a[i]);
	}
}
main(){
	long a[100000],n,k;
	printf("Nhap n = ");
	scanf("%d",&n);
	printf("Nhap k =");
	scanf("%d",&k);
	nhap(a,n);
	xuat(a,n);
	printf("Mang sau khi xoa: ");
	xoa(a,n,k);
}
