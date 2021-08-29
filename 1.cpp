#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>
#include <malloc.h>
#include <windows.h>

const int LEFT_ARROW = 75;
const int UP_ARROW = 72;
const int RIGHT_ARROW = 77;
const int DOWN_ARROW = 80;
const int ENTER = 13;
const int ESC = 27;
const int BACKSPACE = 8;
const int TAB = 9;

int readDataFromFile(const char fileName[], int *n, int *h) {
    
}

void showFirstMenu(int maxx, int hmaxx, int maxy, int hmaxy) {
    cleardevice();
    setcolor(3);
    rectangle(10, 10, maxx - 10, maxy - 10);
    settextstyle(3, 0, 4);
    char *txt1[] = {"DO AN CO SO", "Ma de tai: 802 - GVHD: Nguyen Van Nguyen", "SV: Ho Van Vy | MSV: 102190200 | 19TCLC_DT4", "MENU", "Nhan Enter de mo menu, Esc de thoat chuong trinh"};
    outtextxy(hmaxx - textwidth(txt1[0]) / 2, 20, txt1[0]);
    setcolor(2);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(txt1[1]) / 2, 90, txt1[1]);
    outtextxy(hmaxx - textwidth(txt1[2]) / 2, 120, txt1[2]);
    setcolor(4);
    settextstyle(3, 0, 4);
    outtextxy(hmaxx - textwidth(txt1[3]) / 2, hmaxy - textheight(txt1[3]) / 2, txt1[3]);
    setcolor(3);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(txt1[4]) / 2, maxy - 20, txt1[4]);
}

void showMenu2(int maxx, int hmaxx, int maxy, int hmaxy, int choice, char *menuList[], int lenMenu, char guide[]) {
    int i;
    cleardevice();
    setcolor(3);
    rectangle(10, 10, maxx - 10, maxy - 10);

    int tmp = maxy / 3;
    settextstyle(3, 0, 3);
    for (i = 0; i < lenMenu; i++) {
        if (i == choice)
            setcolor(4);
        else
            setcolor(2);
        tmp += textheight(menuList[i]) + 10;
        outtextxy(hmaxx - textwidth(menuList[i]) / 2, tmp, menuList[i]);
    }

    setcolor(3);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(guide) / 2, maxy - 20, guide);
}

void showBox(int maxx, int hmaxx, int maxy, int hmaxy, int chooseBox, int heightBox, int widthBox, int marginBox) {
        char txt0[] = "Nhap ten file: ", txt1[] = "Nhap n: ", txt2[] = "Nhap h: ";
        cleardevice();

        if (chooseBox == 0) {
            setcolor(3);
            rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);
            outtextxy(hmaxx - widthBox / 2 - textwidth(txt0), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt0) / 2, txt0);
        } else {
            // Box n
            chooseBox == 1 ? setcolor(4) : setcolor(3);
            rectangle(hmaxx - widthBox / 2, hmaxy - (heightBox + marginBox), hmaxx + widthBox, hmaxy - marginBox);

            // Box h
            chooseBox == 2 ? setcolor(4) : setcolor(3);
            rectangle(hmaxx - widthBox / 2, hmaxy + marginBox, hmaxx + widthBox, hmaxy + (heightBox + marginBox));

            setcolor(3);
            outtextxy(hmaxx - widthBox / 2 - textwidth(txt1), hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(txt1) / 2, txt1);
            outtextxy(hmaxx - widthBox / 2 - textwidth(txt1), hmaxy + (heightBox + marginBox) - heightBox / 2 - textheight(txt1) / 2, txt2);
        }

    setcolor(3);
    rectangle(10, 10, maxx - 10, maxy - 10);
        char guide[] = "Dung phim tab de di chuyen giua cac box, enter de xac nhan, ESC de quay lui";
    setcolor(3);
    settextstyle(3, 0, 2);
    outtextxy(hmaxx - textwidth(guide) / 2, maxy - 20, guide);
}

main(){
	int i;
    char keyPress;
    int choice;
    int heightBox = 40, widthBox = 200, marginBox = 25;

    int n, h, keyPressLocal;
    char ch[100] = "";
    int it = 0, it2 = 0;
    char ch2[100] = "";
    // 0: goto BOX1, 1: goto INPUT_DATA_FROM_FILE
    int route = 0;
    
	initwindow(960,540);
	int maxx = getmaxx();
    int hmaxx = maxx / 2;
    int maxy = getmaxy();
    int hmaxy = maxy / 2;
MENU_FIRST:
    showFirstMenu(maxx, hmaxx, maxy, hmaxy);
    do {
        keyPress = getch();
        if (keyPress != 0) printf("\a");
    } while (keyPress != ENTER && keyPress != ESC);
    if (keyPress == ESC) exit(0);
MENU_SECOND:   
    char *mainMenuList[] = {"Nhap du lieu tu file", "Nhap du lieu tu ban phim"};
    int lengthMainMenuList = 2;
    char guide1[] = "Dung phim mui ten de di chuyen len xuong, Enter de chon, ESC de quay lui";
    showMenu2(maxx, hmaxx, maxy, hmaxy, 0, mainMenuList, lengthMainMenuList, guide1);

    choice = 0;
    do {
        keyPress = getch();
        //if (keyPress != 0) printf("\a");

        if (keyPress == UP_ARROW)
            choice = (choice - 1) < 0 ? lengthMainMenuList - 1 : choice - 1;
        else if (keyPress == DOWN_ARROW)
            choice = (choice + 1) % lengthMainMenuList;
        else if (keyPress == ESC) {
            goto MENU_FIRST;
        }
        showMenu2(maxx, hmaxx, maxy, hmaxy, choice, mainMenuList, lengthMainMenuList, guide1);
    } while (keyPress != ENTER);

    // Nhap du lieu tu file
    if (choice + 1 == 1) {
INPUT_DATA_FROM_FILE:
        // ve khung bao quanh
        cleardevice();
        setcolor(3);
        rectangle(10, 10, maxx - 10, maxy - 10);

        char fileInputName[100];
        int it = 0, keyPressLocal;
        showBox(maxx, hmaxx, maxy, hmaxy, 0, heightBox, widthBox, marginBox);
        do {
            char tmp = getch();
            if (tmp != 0)  printf("\a");

            if (tmp == BACKSPACE) {
                it = it < 0 ? 0 : it - 1;
                fileInputName[it] = '\0';
            } else if (tmp == ESC) {
                goto MENU_SECOND;
            } else {
                fileInputName[it] = tmp;
                fileInputName[it + 1] = '\0';
                it++;
            }
            keyPressLocal = tmp;
            cleardevice();
            showBox(maxx, hmaxx, maxy, hmaxy, 0, heightBox, widthBox, marginBox);
            outtextxy(hmaxx - widthBox / 2 + 5, hmaxy - (heightBox + marginBox) + heightBox / 2 - textheight(fileInputName) / 2, fileInputName);
        } while (keyPressLocal != ENTER);

        fileInputName[it - 1] = '\0';
        int errStatus = readDataFromFile(fileInputName, &n, &h);
        if (errStatus == 0) {
            char textError[] = "File khong ton tai. Vui long nhap lai ten file!";
            setcolor(4);
            outtextxy(hmaxx - textwidth(textError) / 2, hmaxy - marginBox - heightBox - textheight(textError) - 20, textError);
            getch();
            goto INPUT_DATA_FROM_FILE;
        } else {
            // Dieu kien bai toan
            if (n < 10 || n > 1e6 || h < 1 || h > 54) {
                setcolor(3);
                char text[] = "Vui long nhap 10 <= N <= 10^6, 1 <= H <= 54";
                outtextxy(hmaxx - textwidth(text) / 2, hmaxy - marginBox - heightBox - textheight(text) - 20, text);
                getch();
                goto INPUT_DATA_FROM_FILE;
            }
            route = 1;
            goto EXPORT_DATA;
        }
    }
    EXPORT_DATA:
        // MENU
        cleardevice();
        char *menuTmp[] = {"Xuat file", "Xuat man hinh"};
        int lengthMenuTmp = 2;
        char guide3[] = "Dung phim mui ten de di chuyen len xuong, Enter de chon, ESC de quay lui";
        showMenu2(maxx, hmaxx, maxy, hmaxy, 0, menuTmp, lengthMenuTmp, guide3);
        choice = 0;
        do {
            keyPress = getch();
            if (keyPress != 0) printf("\a");
            if (keyPress == UP_ARROW)
                choice = (choice - 1) < 0 ? lengthMainMenuList - 1 : choice - 1;
            else if (keyPress == DOWN_ARROW)
                choice = (choice + 1) % lengthMainMenuList;
            else if (keyPress == ESC) {
                if (route == 1) {
                    goto INPUT_DATA_FROM_FILE;
                } else {
                    goto BOX1;
                }
            }
            char guide4[] = "Dung phim mui ten de di chuyen len xuong, Enter de chon, ESC de quay lui";
            showMenu2(maxx, hmaxx, maxy, hmaxy, choice, menuTmp, lengthMenuTmp, guide4);
        } while (keyPress != ENTER);
BOX1:;
}
