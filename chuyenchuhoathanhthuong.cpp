#include <stdio.h>
char ch;
int tg;
main(){
	printf("nhap chu hoa can chuyen doi: ");
	nhap:;
	scanf("%c",&ch);
	tg=(int) ch;
	if ((tg>64)and(tg<97)) {
	    tg+=32;
		ch=(char) tg;
		printf("ki tu da chuyen doi la: %c",ch);	
	}
	else{
	    printf("ki tu vua nhap khong phai la chu hoa, nhap lai: ");
		goto nhap;
	}
}
