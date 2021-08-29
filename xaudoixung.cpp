#include <stdio.h>
#include <string.h>
main(){
	char a[256];
	int i,n,kt=1;//gets(a);
	printf("Nhap xau: ");
	scanf("%s",&a);
	n=strlen(a);
	for (i=0;i<=n/2;i++)
		if (a[i] != a[n-1-i]){
			kt=0;
			break;
		}
	if (kt==1) printf("xau da nhap doi xung");
	else printf("xau da nhap khong doi xung");
}
