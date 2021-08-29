#include <stdio.h>
char ch;
int tg;
main(){
	printf("Nhap chu cai can kiem tra:");
	scanf("%c",&ch);
	printf("%c",ch);
	tg=(int) ch;
	if ((tg>=65) and (tg<97)) printf(" la chu hoa");
        else printf(" la chu thuong");   
}
