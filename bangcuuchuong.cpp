#include <stdio.h>
main(){
	printf("________________Bang cuu chuong________________\n\n");
	int i,j,k;
	for(i=1;i<=10;i++){
		for(j=2;j<=10;j++)
		printf("%dx%2d=%2d ",j,i,i*j);
		printf("\n");
	}
}
