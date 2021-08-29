#include <stdio.h>
char ch;
int tg;
main(){
	printf("nhap chu thuong can chuyen doi: ");
	scanf("%c",&ch);
	tg=(int) ch;
	if ((tg>96)and(tg<123)){
		tg-=32;
		ch=(char) tg;
		printf("ki tu da chuyen doi la: %c",ch);
		}
	else printf("ki tu vua nhap khong phai la chu thuong");
}
