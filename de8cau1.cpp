#include <stdio.h>
#include <math.h>
main(){
	float a,b,c,x,x1,x2,x3,x4,tg1,tg2,d;
	printf("Nhap cac he so a, b,c: ");
	scanf("%f %f %f",&a,&b,&c);
	printf("Phuong trinh: %0.2fx^4 + %0.2fx^2 + %0.2f =0\n",a,b,c);
	if (a==0) printf("Phuong trinh khong phai phuong trinh bac 4!");
	else {
		d=b*b-4*a*c;
		if (d==0){
			x=-b/(2*a);
			if (x>0){
				printf("Phuong trinh co 2 nghiem phan biet:\n");
				x1=sqrt(x);
				x2=-sqrt(x);
				printf("x1 = %0.2f \n x2 = %0.2f",x1,x2);
			}
			else 
				if (x==0) printf("Phuong trinh co nghiem kep x1 = x2 = 0");
				else 
					if (x<0) printf("Phuong trinh vo nghiem.");
		}
		else 
			if (d<0) printf("Phuong trinh vo nghiem.");
			else {
				tg1=(-b+sqrt(d))/(2*a);
				tg2=(-b-sqrt(d))/(2*a);
				if (tg1>0&&tg2<0){
					x1=sqrt(tg1);
					x2=-sqrt(tg1);
					printf("Phuong trinh co 2 nghiem: x1 = %0.2f va x2 = %0.2f",x1,x2);
				}
				else
					if (tg1<0&&tg2>0){
						x1=sqrt(tg2);
						x2=-sqrt(tg2);
						printf("Phuong trinh co 2 nghiem: x1 = %0.2f va x2 = %0.2f",x1,x2);
					}
					else 
						if ((tg1==0 && tg2<0) || (tg1<0 && tg2==0) || (tg1==0 && tg2==0))
							printf("Phuong trinh co nghiem kep x1 = x2 = 0");
						else 
							if (tg1>0 && tg2>0){
								x1=sqrt(tg1);
								x2=-sqrt(tg1);
								x3=sqrt(tg2);
								x4=-sqrt(tg2);
								printf("Phuong trinh co 4 nghiem phan biet:\nx1 = %0.2f, x2 = %0.2f, x3 = %0.2f, x4 = %0.2f",x1,x2,x3,x4);
							}
			}
	}
}
