#include <iostream>
#include <string>
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
const int DEL = 127;

void Menu1(int, int, int, int);
void BoxMenu2(int, int, int, int, int, int, int, int);
void Menu2(int, int, int, int, int, int, int, char*&, char*&);
void Login(int, int, int, int, int, int, int, char*&, char*&, char**, char**, int [], int, int&);
void ShowMenu3(int, int, int, int, int, int);
void Menu3(int, int, int, int, int, int, int, int);
void Menu3_1(int, int, int, int, int, int, int, int);
void Menu3_2(int, int, int, int, int, int, int, int);
void Menu3_3(int, int, int, int, int, int, int, int);
void ShowMenu3_4(int, int, int, int, int);
void Menu3_4(int, int, int, int, int, int, int, int);
void Menu3_5(int, int, int, int, int, int, int, int);
void Menu4_1(int, int, int, int, int, int, int, int);
void BoxMenu4_2(int, int, int, int, int, int, int);
void Menu4_2(int, int, int, int, int, int, int, int);
void Menu5_1(int, int, int, int, int, int, int, int);
void Menu5_2(int, int, int, int, int, int, int, int);
void Menu5_3(int, int, int, int, int, int, int, int);
