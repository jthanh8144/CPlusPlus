#include<stdio.h>
#include<string.h>

int main(){
	int n,kt=1;
	char a[100];
	printf("Nhap xau can kiem tra: ");
	scanf("%s",&a);
	n=strlen(a);
	for (int i = 0; i < n/2; i++)
		if (a[i] != a[n-1-i]){
			kt = 0;
			break;
		}
	if (kt == 0) printf("khong phai palindrome");
	else printf("palindrome");
}
