#include <stdio.h>
#include <graphics.h>
#include <math.h>
#define pi  3.141592654

int main() {
	int n, j = 2, r = 100;
	float x, y, goc;
	printf("Nhap n = ");
	scanf("%d", &n);
	goc = 360/n;
	int p[2*(n+1)];
	initwindow(500,500);
	//setwindowtitle('Ve Da Giac');
	/*moveto(getmaxx()/2, getmaxy()/2);
	p[0] = getx() + r;
	p[1] = gety() + r;
	for (int i = 1; i < n; i++){
		x = r * sin((goc*pi)/180);
		y = r * cos((goc*pi)/180);
		p[j++] = x;
		p[j++] = y;
		moveto(x, y);
	}
	drawpoly(n+1, p);*/
	return 0;
}
