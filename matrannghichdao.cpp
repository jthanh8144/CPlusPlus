#include <stdio.h>
typedef long mt[100][100];
void nhap(mt a,long n){
	for (long i=1;i<=n;i++)
		for (long j=1;j<=n;j++){
			printf("A[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
}
void xuat(mt a,long n){
	for (long i=1;i<=n;i++){
		for (long j=1;j<=n;j++) printf("%10d",a[i][j]);
		printf("\n");
	}
}
long det2(mt a){
	long d,i;
	d=(a[i][i]*a[2][2])-(a[1][2]*a[2][1]);
	return d;
}
long det3(mt a){
	long d;
	d=(a)
}
main(){
	mt a;
	long n,i,j;
	printf("Nhap n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	
}
