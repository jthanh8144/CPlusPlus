#include <iostream>
#include <string>
#include <stdlib.h>
#include <conio.h>
#include "graphics.h"

using namespace std;

const int LEFT_ARROW = 75;
const int UP_ARROW = 72;
const int RIGHT_ARROW = 77;
const int DOWN_ARROW = 80;
const int ENTER = 13;
const int ESC = 27;
const int BACKSPACE = 8;
const int TAB = 9;

void Menu1(int maxx, int hmaxx, int maxy, int hmaxy) {
	char key;
	char *txt1[] = {"DO AN LAP TRINH", "GVHD: Phan Thanh Tao - Phan Chi Tung", "SVTH: Vo Van Thanh - Nguyen Duy Thinh", 
		"De tai: Phan mem quan li cua hang Laptop", "Dang Nhap", "Nhan Enter de dang nhap, Esc de thoat chuong trinh"};
    cleardevice();
    setcolor(3);
    rectangle(10, 10, maxx - 20, maxy - 20);
    settextstyle(3, 0, 4);
    outtextxy(hmaxx - textwidth(txt1[0]) / 2, 20, txt1[0]);
    setcolor(2);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(txt1[1]) / 2, 90, txt1[1]);
    outtextxy(hmaxx - textwidth(txt1[2]) / 2, 120, txt1[2]);
	setcolor(14);
	settextstyle(3, 0, 4);
	outtextxy(hmaxx - textwidth(txt1[3]) / 2, 150, txt1[3]);
    setcolor(4);
    settextstyle(3, 0, 4);
    outtextxy(hmaxx - textwidth(txt1[4]) / 2, hmaxy - textheight(txt1[4]) / 2, txt1[4]);
    setcolor(3);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(txt1[5]) / 2, maxy - 40, txt1[5]);
	do {
        key = getch();
    } while (key != ENTER && key != ESC);
    if (key == ESC) exit(0);
}

void ImportID(int maxx, int hmaxx, int maxy, int hmaxy, int chooseBox, int heightBox, int widthBox, int marginBox, int x, int y, char* &ID){
	char id[10], tmp;
	int i = 0;
	do{
		tmp = getch();
		if (tmp == BACKSPACE){
			i = i<0 ? 0 : i-1;
			ID[i] = '\0';
		} else if (tmp = ESC) Menu1(maxx, hmaxx, maxy, hmaxy);
		else {
			ID[i] = tmp;
			ID[i+1] = '\0';
			i++;
		}
		outtextxy(hmaxx - widthBox/2 + 5, hmaxy - (heightBox + marginBox) + heightBox/2 - textheight(ID)/2, ID);
	}while (tmp != ENTER);
	ID[i-1] = '\0';

}

void Menu2(int maxx, int hmaxx, int maxy, int hmaxy, int chooseBox, int heightBox, int widthBox, int marginBox, char* &ID, char* &Pass) {
	char id[10], tmp;
	int i = 0, keyPress;
	cleardevice();
	char txt1[] = "Tai khoan: ", txt2[] = "Mat khau: ", txt3[] = "Dung phim mui ten de di chuyen len xuong, Enter de dang nhap, ESC de quay lai";
	setcolor(3);
	rectangle(10, 10, maxx - 20, maxy - 20);
	outtextxy(hmaxx - textwidth(txt3) / 2, maxy - 40, txt3);
	outtextxy(hmaxx - widthBox / 2 - textwidth(txt1), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt1) / 2, txt1);
	outtextxy(hmaxx - widthBox / 2 - textwidth(txt2), hmaxy + (heightBox + marginBox) - heightBox / 2 - textheight(txt2) / 2, txt2);
	if (chooseBox == 1){
		setcolor(4);
		rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
		setcolor(3);
		rectangle(hmaxx - widthBox / 2, hmaxy + marginBox, hmaxx + widthBox, hmaxy + (heightBox + marginBox));
		
		
	}
	else{
		rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
		setcolor(4);
		rectangle(hmaxx - widthBox / 2, hmaxy + marginBox, hmaxx + widthBox, hmaxy + (heightBox + marginBox));
	}
}

int main(){
	char key;
	int heightBox = 40, widthBox = 200, marginBox = 25;

	initwindow(1000,700);
	int maxx = getmaxx();
    int hmaxx = maxx / 2;
    int maxy = getmaxy();
    int hmaxy = maxy / 2;
	int choice = 1, lengthMainMenuList = 2, i = 0, j = 0;
	char *ID, *Pass, tmp;
	ID = new char[10];
	Pass = new char[10];
	Menu2(maxx, hmaxx, maxy, hmaxy, choice, heightBox, widthBox, marginBox, ID, Pass);
	do{
		key = getch(); 
        if (key == UP_ARROW)
			choice = (choice - 1) < 0 ? lengthMainMenuList - 1 : choice - 1;
        else if (key == DOWN_ARROW)
            choice = (choice + 1) % lengthMainMenuList;
        else if (key == ESC) 
            Menu1(maxx, hmaxx, maxy, hmaxy);
        Menu2(maxx, hmaxx, maxy, hmaxy, choice, heightBox, widthBox, marginBox, ID, Pass);
		/*if (choice = 1){
			do{
				tmp = getch();
				if (tmp == BACKSPACE){
					i = i<0 ? 0 : i-1;
					ID[i] = '\0';
				} else if (tmp = ESC) Menu1(maxx, hmaxx, maxy, hmaxy);
				else {
					ID[i] = tmp;
					ID[i+1] = '\0';
					i++;
				}
				outtextxy(hmaxx - widthBox/2 + 5, hmaxy - (heightBox + marginBox) + heightBox/2 - textheight(ID)/2, ID);
			}while (tmp != ENTER);
			ID[i-1] = '\0';*/
			cleardevice();
			Menu2(maxx, hmaxx, maxy, hmaxy, choice, heightBox, widthBox, marginBox, ID, Pass);
			//outtextxy(hmaxx - widthBox / 2 + 5, hmaxx - (heightBox + marginBox) + heightBox / 2 - textheight(ID)/2, ID);
		/*}else{
			
		}*/
    } while (key != ENTER);
	
	Menu2(maxx, hmaxx, maxy, hmaxy, choice, heightBox, widthBox, marginBox, ID, Pass);
	
	return 0;
}
