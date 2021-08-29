#include <stdio.h>
int main(){
	char ch,tg;
	printf("Nhap chu cai: ");
	scanf("%c",&ch);
	tg=(int) ch;
	if ((tg>64)and(tg<97)) {
	    tg+=32;
		ch=(char) tg;
		printf("ki tu la chu hoa, chuyen thanh chu thuong: %c",ch);
		return 0;
	}
	if ((tg>96)and(tg<123)){
		tg-=32;
		ch=(char) tg;
		printf("ki tu la chu thuong, chuyen thanh chu hoa: %c",ch);
		return 0;
		}
}
