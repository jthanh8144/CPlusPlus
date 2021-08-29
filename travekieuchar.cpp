#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* intien(int a){//toi da 10 chu so
	fflush(stdin);
	char t[20];
	itoa(a,t,10);
	int n,l = strlen(t), i=l;
	if (l%3 == 0) n = l/3-1;
	else n = l/3;
	while (n>0){
		t[i+n-1] = t[i-1];
		t[i+n-2] = t[i-2];
		t[i+n-3] = t[i-3];
		t[i+n-4] = ',';
		n--;
		i-=3;
	}
	return t;
}
main(){
	int a = 10000000;
	printf("%s",intien(a));
}
