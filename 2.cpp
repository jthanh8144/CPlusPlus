#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <graphics.h>
#include <stdlib.h>
using namespace std;

const int LEFT_ARROW = 75;
const int UP_ARROW = 72;
const int RIGHT_ARROW = 77;
const int DOWN_ARROW = 80;
const int ENTER = 13;
const int ESC = 27;
const int BACKSPACE = 8;
const int TAB = 9;
const int DEL = 127;

const int widthWindow = 1500, maxx = 1499;
const int heightWindow = 800, maxy = 799;
const int hmaxx = maxx / 2;
const int hmaxy = maxy / 2;
const int heightBox = 40, widthBox = 200, marginBox = 25;

void ShowNotification(char* ch) {
	char key;
	char txt[] = "Nhan Enter de tiep tuc";
	cleardevice();
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(ch) / 2, hmaxy - textheight(ch) / 2, ch);
	settextstyle(3, 0, 2);
	outtextxy(hmaxx - textwidth(txt) / 2, maxy - 40, txt);
	do {
		key = getch();
	} while (key != ENTER);
}

void Menu3(int a){
}

void BoxMenu3_3(int choice) {
	cleardevice();
	char* txt[] = { "Nhan Enter de tiep tuc, ESC de quay lai", "Tu ngay: ", "Den ngay: ", "In hoa don: " };
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt[0]) / 2, maxy - 40, txt[0]);
	outtextxy(hmaxx - textwidth(txt[3]) / 2, 20, txt[3]);
	rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
	switch (choice) {
		case 1: 
			outtextxy(hmaxx - textwidth("YYYYMMDD") / 2, hmaxy - marginBox - heightBox - textheight("YYYYMMDD") - 20, "YYYYMMDD");
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[1]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[1]) / 2, txt[1]);
			break;
		case 2: 
			outtextxy(hmaxx - textwidth("YYYYMMDD") / 2, hmaxy - marginBox - heightBox - textheight("YYYYMMDD") - 20, "YYYYMMDD");
			outtextxy(hmaxx - widthBox / 2 - textwidth(txt[2]), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt[2]) / 2, txt[2]);
			break;
	}
}

void Menu3_3(int lengthMenu3List) {
	int i = 0, j = 0, keyPress = 0;
	char tmp;
	char* TN, * DN;
	TN = new char[8]; TN[i] = '\0';
	DN = new char[8]; DN[j] = '\0';
TuNgay:
	cleardevice();
	BoxMenu3_3(1);
	outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TN) / 2, TN);
	do {
		tmp = getch();
		if (tmp == BACKSPACE) {
			i = i <= 0 ? 0 : i - 1;
			TN[i] = '\0';
		}
		else if (tmp == ESC) {
			Menu3(lengthMenu3List);
			break;
		}
		else if (tmp != ENTER && (tmp < 48 || tmp > 57)) ShowNotification("SDT chi gom so!");
		else {
			TN[i] = tmp;
			TN[i + 1] = '\0';
			i++;
		}
		keyPress = tmp;
		cleardevice();
		BoxMenu3_3(1);
		outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(TN) / 2, TN);
	} while (keyPress != ENTER);
	TN[i - 1] = '\0';

	cout << TN << endl;
	Menu3(lengthMenu3List);
}

int main(){
	initwindow(widthWindow, heightWindow);
	settextstyle(3, 0, 2);
	Menu3_3(4);
	return 0;
}
