#include <stdio.h>
main(){
	char ch;
	printf("Nhap vao chu: ");
	scanf("%c",&ch);
	if (ch=='F'||ch=='f') printf("Bam chon menu File");
	if (ch=='H'||ch=='h') printf("Bam chon menu Help");
}
