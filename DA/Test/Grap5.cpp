#include "Grap5.h"

void initGrap(){
	initwindow(1500, 800);
	/*maxx = getmaxx();
	maxy = getmaxy();
	hmaxx = maxx / 2;
	hmaxy = maxy / 2;*/
}

/*void Menu0(char* ch) {
	char key;
	char txt[] = "Nhan Enter de dang nhap, Esc de thoat chuong trinh";
	
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(ch) / 2, hmaxy - textheight(ch) / 2, ch);
	settextstyle(3, 0, 2);
	outtextxy(hmaxx - textwidth(txt) / 2, maxy - 40, txt);
	
	do {
		key = getch();
	} while (key != ENTER && key != ESC);
	if (key == ESC) exit(0);
}*/
