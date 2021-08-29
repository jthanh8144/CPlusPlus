#include <stdio.h>
#include <math.h>
main(){
	const float pi=3.14;
	float x,fx;
	printf("Nhap x = ");
	scanf("%f",&x);
	fx=(pow(x,2/3)+pow(x,5)+log(pow(x,4)+1))/(x*x+pi/4);
	printf("f(%0.3f) = %0.3f",x,fx);
}
