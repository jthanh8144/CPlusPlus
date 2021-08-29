#include <stdio.h>
int n;
main(){
	printf("Nhap nam can kiem tra: ");
	scanf("%d",&n);
    if (n%100==0){
    	if (n%400==0) printf("%d la nam nhuan",n);
    	else printf("%d khong phai la nam nhuan",n);
	}
	else 
	    if (n%4==0) printf("%d la nam nhuan",n);
	    else printf("%d khong phai la nam nhuan",n);
}
