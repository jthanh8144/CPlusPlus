#include <stdio.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#define pi 3.141592654

int main(){
	int n, ox, oy, r = 100;
	float a, b, x, y, gq, goc = 0;
	printf("Nhap n = ");
	scanf("%d", &n);
	gq = 360/n;
	initwindow(510,514);
	//setWindowTitle(VeDaGiac);
	ox = getmaxx()/2;
	oy = getmaxy()/2;
	putpixel(ox, oy, 2);
	moveto(ox, oy - r);
	for (int i = 0; i < n; i++){
		goc += gq;
		x = r * sin((goc*pi)/180);
		a = ox + x;
		y = r * cos((goc*pi)/180);
		b = oy - y;
		lineto(int(a), int(b));
		delay(1000);
	}
	getch();
	return 0;
}
