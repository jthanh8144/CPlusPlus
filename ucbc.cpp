#include <stdio.h>
void nhap(int a[],int n){
	for (int i=0;i<n;i++){
		printf("a[%d] = ",i);
		scanf("%d",&a[i]);
	}
}
void xuat(int a[],int n){
	printf("Mang vua nhap la: ");
	for (int i=0;i<n;i++) printf("%d ",a[i]);
	printf("\n");
}
int ucln(int a,int b){
	if (a%b==0) return b;
	if (b%a==0) return a;
	if (a==b) return a;
	else 
		if (a>b) return(ucln(a%b,b));
		else return(ucln(a,b%a));
}
int bcnn(int a,int b){
	return(a*b/ucln(a,b));
}
int uc(int a[],int n){
	if (n<1) return(a[0]);
	int i,d=ucln(a[0],a[1]);
	for (i=2;i<n;i++) d=ucln(d,a[i]);
	return d;
}
int bc(int a[],int n){
	if (n<1) return a[0];
	int i,d=bcnn(a[0],a[1]);
	for (i=2;i<n;i++) d=bcnn(d,a[i]);
	return d;
}
main(){
	int a[10000],n;
	printf("Nhap n = ");
	scanf("%d",&n);
	nhap(a,n);
	xuat(a,n);
	printf("UCLN cua mang la: %d\n",uc(a,n));
	printf("BCNN cua mang la: %d\n",bc(a,n));
}
