#include <stdio.h>
#include <conio.h>
#include <graphics.h>

int main() {
	initwindow(500, 500);
	int x = getmaxx() / 2, y = getmaxy() / 2, r = 10, xoa = 0, i = 0;
	putpixel(x, y, 15);
	while(!kbhit()){
		setcolor(15);
		//arc(x, y, 0, 90, r);
		circle(x, y, r);
		delay(200);
		r += 10;
	
		xoa = r - 10;
		setcolor(0);
		delay(200);
		//arc(x, y, 0, 90, xoa);
		circle(x, y, xoa);
		
		i++;
		if (i == 5){
			r = 10;
			i = 0;
		}
	}
	getch();
	closegraph();
	return 0;
}
