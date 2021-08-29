#include<stdio.h>
#include<stdlib.h>

main(){
	FILE *f;
	char c[100];
	f = fopen("D:\test.txt","r");//ten file là tên file can doc hoac duong dan toi file, cung co the sd 1 xau vd nhu sau
//	char a[100] = "file.txt";
//	f = fopen(a,"r");
//	"r" la che do mo file, co nghia la read, chi mo file de doc, co the tim them cac che do mo khac nhu w, w+, a, a+, r+ de biet them chi tiet
// doc file in ra man hinh
	while (fgets(c,100,f)){//fgets() dung de lay chuoi c 100 ki tu tu file f, dung while (fgets() ) co nghia la khi nao c != gia tri NULL thi in ra man hinh
		printf("%s",c);		// cung co the dung fscanf tuong tu fgets
	}
// cong thuc chung cua fprintf, fscanf, fgets... la fprintf(ten con tro file, "chuoi dinh dang", bien);
// ghi vao file
	fprintf(f,"chuoi hay so can ghi vao file vd %d",c);//tuy vao che do mo file moi co the ghi vao file, cac che do cho phep ghi la w, w+, a, a+
// doc file vao mang, vd mang nhu sau
/* 4 3		//4 hang 3 cot
   1 2 3
   4 5 6
   7 8 9
   0 1 2*/
	int a[100][100], m, n;
	fscanf(f,"%d %d",&m,&n);
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++) fscanf(f, "%d", &a[i][j]);
// ghi mang vao file cung tuong tu nhu tren thay fscanf thanh fprintf la duoc
	fclose(f);//co mo file thi nho phai dong file, file tao ra chua dong se k doc ra du lieu duoc
}
//biet gi chi het roi do fen :V
