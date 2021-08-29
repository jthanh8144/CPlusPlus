#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void nhaptenf(char fname[], char tg[]){
	char name[100], bname[100 ]= "D:\\DACS\\";
	printf("Nhap ten file can doc: ");
	scanf("%s",&name);
	strcpy(tg,name);
	strcat(bname, name);
	strcat(bname, ".txt");
	strcpy(fname, bname);	
}

void inf(const char *file){
	char c[100];
	FILE *f = fopen(file,"r");
	////system("cls");
	while (fgets(c,100,f)){
		printf("%s",c);
	}
	printf("\n");
	fclose(f);
}

main(){
	FILE *f;
	char fname[100], name[100];
	nhaptenf(fname, name);
	f = fopen(fname,"a+");
	inf(fname);
}
