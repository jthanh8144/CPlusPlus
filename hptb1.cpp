#include <stdio.h>
main(){
	float x,y;
	int a,b,c,d,e,f;
	printf("Nhap cac he so a, b, c, d, e, f:\n");
	scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
	printf("%dx + %dy = %d\n%dx + %dy = %d\n",a,b,c,d,e,f);
	x=(f-e*c/b)/(d-e*a/b);
	y=(c-a*x)/b;
	printf("x = %0.3f \ny = %0.3f",x,y);
}
