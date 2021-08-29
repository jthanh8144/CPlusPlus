#include<stdio.h>

void yc(int a[], int n, int c){
	for(int k = n; k >= 1; k--)
		for(int i = 1; i <= k; i++) a[i] = a[i-1]*c + a[i];
	for (int i = 0; i <= n; i++) printf("%5d", a[i]);
}

int main(){
	int a[100], n, c, tg = 1;
	printf("Nhap bac cua da thuc n = ");
	scanf("%d",&n);
	printf("Nhap cac he so cua da thuc.\n");
	for(int i = 0; i<= n; i++){
		printf("a[%d] = ",i);
		scanf("%d", &a[i]);
	}
	while(tg)
	{
		printf("\nNhap gia tri c = ");
		scanf("%d",&c);
		if (c != 0){
			if (c > 0) printf("He so cua p(y + %d) la: ",c);
			else printf("He so cua p(y %d) la: ",c);
		}
		else printf("He so cua p(y) la: ");
		yc(a, n, c);
		printf("\n\nNhap 1 de tiep tuc tinh, nhap 0 de thoat chuong trinh: ");
		scanf("%d",&tg);	
	}
	return 0;
}
