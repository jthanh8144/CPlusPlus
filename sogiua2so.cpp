#include <stdio.h>
main(){
	int a,b,c,max,min;
	printf("Nhap ba so a, b, c: ");
	scanf("%d %d %d",&a,&b,&c);
	max=a;
	if (b>max) max=b;
	if (c>max) max=c;
	min=a;
	if (b<min) min=b;
	if (c<min) min=c;
	printf("So can tim la: %d",a+b+c-max-min);
}
