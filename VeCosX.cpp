#include <iostream>
#include <graphics.h>
#include <math.h>
#define pi 3.14

int main(){
	int ox, oy, dx = 50;
	float x, y;
	initwindow(500, 500);
	ox = getmaxx()/2;
	oy = getmaxy()/2;
	line(ox, 0, ox, getmaxy());
	line(0, oy, getmaxx(), oy);
	
	for (int i = -90; i <= 450; i++){
		x = i*pi/180;
		y = dx * cos(x) + oy;
		x = dx * (x - pi) + ox;
		putpixel(x, y, 3);
	}
	getch();
	return 0;
}
