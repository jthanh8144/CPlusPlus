#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <graphics.h>

int random(int min, int max){
	return min + rand() % (max + 1 - min);
}

int main() {
	initwindow(800, 500);
	srand((int) time(0));
	int x, y, m;
	while (!kbhit()){
		x = random(0, getmaxx());
		y = random(0, getmaxy());
		m = random(0, 15);
		putpixel(x, y, m);
		delay(100);
	}
	//getimage()
	getch();
	closegraph();
	return 0;
}
