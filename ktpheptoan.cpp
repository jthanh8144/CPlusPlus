#include <stdio.h>
char op;
int tg;
main(){
	printf("Nhap ki tu can kiem tra: ");
	scanf("%c",&op);
	tg=(int) op;
	if ((op==43)||(op==45)||(op==42)||(op==47)||(op==94)||(op==126))
	    printf("Ki tu vua nhap la phep toan");
	else
	    printf("Ki tu vua nhap khong phai la phep toan");
}
