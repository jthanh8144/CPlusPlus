#include <stdio.h>
main(){
	const float pi=3.14;
	float R,S,L;
	printf("Nhap ban kinh R: ");
	scanf("%f",&R);
	S=pi*R*R;
	L=2*pi*R;
	printf("Dien tich S = %0.3f\nChu vi L = %0.3f",S,L);
}
