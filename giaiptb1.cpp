#include <stdio.h>
int a,b;//giai pt bac 1
float x;
main() {
	printf("a=");
	scanf("%d",&a);
	printf("b=");
	scanf("%d",&b);
	printf("phuong trinh can giai co dang %d",a);
	if (b!=0){
		if (b>0) printf("x+%d",b);
		    else printf("x%d",b);
		}
	    else printf("x");
	printf("=0 \n");
	if (a==0) {printf("phuong trinh vo nghiem");}
	    else {
	    	x=(float)(-b)/(float)a;
		    printf("nghiem cua phuong trinh la x=%0.3f",x);
		}
}
