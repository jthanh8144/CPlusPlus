#include<stdio.h>
#include<string.h>

void hv(char &a, char &b){
	char tg = a;
	a = b;
	b = tg;
}

int main(){
	int i, j, kt = 0;
	char a[100], b[100];
	printf("Nhap 2 xau can kiem tra: ");
	scanf("%s %s",&a,&b);
	if (strlen(a) == strlen(b)){
		for (i = 0; i < strlen(a) - 1; i++)
			for (j = i + 1; j < strlen(b); j++){
				if (a[i] > a[j]) hv(a[i], a[j]);
				if (b[i] > b[j]) hv(b[i], b[j]);
			}
		for (i = 0; i < strlen(a); i++)
			if (a[i] != b[i]){
				printf("khong phai anagram");
				return 0;
			}
		printf("anagram");
	}
	else printf("khong phai anagram");
}
