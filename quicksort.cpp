#include <stdio.h>
void nhap(int a[],int n){
	for (int i=0;i<n;i++){
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(int a[],int n){
	for (int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}
void quicksort(int a[],int trai,int phai){
	int i=trai,j=phai;
	int giua=a[(trai+phai)/2];
	while (i<=j){
		while (a[i] < giua && i<phai) i++;
		while (a[j] > giua && j>trai) j--;
		if (i<=j){
			int tg=a[i];
			a[i]=a[j];
			a[j]=tg;
			i++;j--;
		}
	}
	if (trai<j) quicksort(a,trai,j);
	if (i<phai) quicksort(a,i,phai);
}
int main(){
	int a[100000],n;
	printf("n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	quicksort(a,0,n-1);
	xuat(a,n);
}
