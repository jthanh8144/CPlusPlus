#include <stdio.h>
#include <math.h>
main(){
	int a,b,c;
	float x1,x2,x,delta;
	printf("Nhap a, b, c: ");
	scanf("%d %d %d",&a,&b,&c);
	delta=b*b-4*a*c;
	if (delta<0) printf("Phuong trinh vo nghiem");
	else{
		if (delta>0){
			x1=(-b+sqrt(delta))/(2*a);
			x2=(-b-sqrt(delta))/(2*a);
			printf("Phuong trinh co 2 nghiem \nx1 = %0.3f \nx2 = %0.3f",x1,x2);
		}
		else{
			x=-b/(2*a);
			printf("Phuong trinh co nghiem kep x = %0.3f",x);
		}
	}
}
