#include <stdio.h>
char ch;
int tg;
main(){
	printf("Nhap ki tu can kiem tra: ");
	scanf("%c",&ch);
	tg=(int) ch;
	if (((tg>64)&&(tg<91))||(tg>96)&&(tg<123))
	    printf("Ki tu vua nhap la chu cai");
	else
	    printf("Ki tu vua nhap khong phai la chu cai");
}
