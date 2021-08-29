#include<stdio.h>

float tinh(int a[], int n, int c){
	float p = a[0];
	for(int i = 1; i <= n; i++) p = p*c + a[i];
	return p;
}

main(){
	int a[100], n, c, tg = 1;
	printf("Nhap bac cua da thuc can tinh: ");
	scanf("%d",&n);
	printf("Cac he so cua da thuc bac %d:\n",n);
	for(int i = 0; i <= n; i++){
		printf("a[%d] = ",i);
		scanf("%d", &a[i]);
	}
	while(tg){		
		printf("Nhap gia tri X can tinh: ");
		scanf("%d",&c);
		float p = tinh(a, n, c);
		printf("Gia tri cua da thuc khi X = %d la: %0.2f\n\n", c, p);
		printf("Nhap 0 de ket thuc chuong trinh, nhap 1 de tiep tuc tinh voi gia tri X moi: ");
		scanf("%d", &tg);
	}
}
