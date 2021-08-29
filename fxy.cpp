#include <stdio.h>
#include <math.h>
main(){
	const float pi=3.14;
	float x,y,tu,mau;
	printf("Nhap x, y: ");
	scanf("%f %f",&x,&y);
	if (x+y>0){
		mau=pow(x*x+y*y,1/3)-(log(x+y)/log(5));
		if (mau!=0){
			tu=atan(x-y)+(pi/4);
		printf("f(%0.3f,%0.3f) =  %0.3f",x,y,tu/mau);
		}
		else printf("Mau bang 0, loi!");
	}
	else printf("Loi tap xac dinh cua ham logarit!");
}
