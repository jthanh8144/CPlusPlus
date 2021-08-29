//5.2 8.2 11.2
#include <stdio.h>
typedef long mt[100][100];
void nhap(mt a,long m, long n){
	for (int i=0;i<m;i++)
		for (int j=0;j<n;j++){
			printf("a[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
}
void xuat(mt a,long m, long n){
	for (int i=0;i<m;i++){
		for (int j=0;j<n;j++) printf("%d	",a[i][j]);
		printf("\n");
	}	
}
void yc(mt a,long m,long n){
	if (m!=n) printf("Ma tran da nhap khong phai ma tran vuong, khong the thuc hien yeu cau de!");
	else {
		for (int i=0;i<n;i++){
			int tg=a[i][i];
			for (int j=0;j<n;j++)
				if (a[i][j]>tg){
					tg=a[i][j];
					a[i][j]=a[i][i];
					a[i][i]=tg;
				}
		}
		printf("Mang sau khi sap xep la:\n");
		xuat(a,m,m);
		long s=0;
		for (int i=0;i<n;i++) s+=a[i][i];
		printf("tong duong cheo s = %d",s);
	}
}
main(){
	mt a;
	long m,n;
	printf("Nhap m, n: ");
	scanf("%d %d",&m,&n);
	nhap(a,m,n);
	printf("Ma tran cap %dx%d da nhap la:\n",m,n);
	xuat(a,m,n);
	yc(a,m,n);
}
