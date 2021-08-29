#include <stdio.h>
char num;
int tg;
main(){
	printf("Nhap ki tu can kiem tra: ");
	scanf("%c",&num);
	tg=(int) num;
	if ((tg>47)&&(tg<58))
	    printf("Ki tu vua nhap la chu so");
	else
	    printf("Ki tu vua nhap khong phai la chu so");
}
