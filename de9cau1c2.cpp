#include <stdio.h>
main(){
	double s=0,x,tg;
	printf("Nhap x = ");
	scanf("%lf",&x);
	tg=1;
	int i=2;
	while (tg>=0.000001){
		s+=tg;
		tg=tg*x*x/(i*(i-1));
		i+=2;
	}
	printf("s = %lf",s);
}
