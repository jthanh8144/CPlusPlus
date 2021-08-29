#include <stdio.h>
void nhap(char ch, int a[],int n){
	for (int i=0;i<n;i++){
		printf("%c[%d] = ",ch,i);
		scanf("%d",&a[i]);
	}
}
void xuat(char ch,int a[],int n){
	printf("Mang %c: ",ch);
	for (int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}
void sxg(int a[],int n){
	for (int i=0;i<n-1;i++)
		for (int j=i+1;j<n;j++){
			if (a[i]<=a[j]){
				int tg=a[i];
				a[i]=a[j];
				a[j]=tg;
			}
		}
}
void gop(int a[],int m,int b[],int n){
	int i,j,k;
	sxg(a,m);
	for (j=0;j<n;j++)
		for (i=0;i<m;i++){
			if (b[j]>a[0]){
				int tg1=a[k];
				for (k=m;k>0;k--) a[k]=a[k-1];
				a[0]=b[j];
				m+=1;
				break;
			}
			if (b[j]<a[m-1]){
				m+=1;
				a[m-1]=b[j];
				break;
			}
			if (b[j]<a[i] && b[j]>a[i+1]){
				for (k=m;k>i+1;k--) a[k]=a[k-1];
				a[k]=b[j];
				m+=1;
				break;
			}
			if (b[j]==a[i]){
				for (k=m;k>i;k--) a[k]=a[k-1];
				m+=1;
				break;
			}
		}
	xuat('r',a,m);
}
main(){
	int a[10000],b[10000],m,n;
	printf("Nhap so phan tu m cua a, n cua b: ");
	scanf("%d %d",&m,&n);
	nhap('a',a,m);
	xuat('a',a,m);
	nhap('b',b,n);
	xuat('b',b,n);
	gop(a,m,b,n);
}
