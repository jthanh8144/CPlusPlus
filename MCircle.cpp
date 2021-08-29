#include <iostream>
#include <graphics.h>

/*void ve8diem(int x0,int y0,int x, int y, int color)
{
	putpixel( x0 + x , y0 + y ,color);
	putpixel( x0 - x , y0 + y ,color);
	putpixel( x0 + x , y0 - y ,color);
	putpixel( x0 - x , y0 - y ,color);
	putpixel( x0 + y , y0 + x ,color);
	putpixel( x0 - y , y0 + x ,color);
	putpixel( x0 + y , y0 - x ,color);
	putpixel( x0 - y , y0 - x ,color);
}
void Mcircle(int x0,int y0,int r)
{
	int x=0;int y=r;
	int p=3-2*r;
	while (x<=y){
		ve8diem(x0,y0,x,y,15);
		if(p<0) p=p+4*x+6;
		else{
			p=p+4*(x-y)+10;
			y=y-1;
		}
		x=x+1;
	}
}*/

void Mcircle(int x0, int y0, int r){
	int x = x0, y = y0+r;
	int p = 3/2-r;
	while (x <= y){
		putpixel(x, y, 3);
		putpixel(y, x, 3);
		putpixel(-y, x, 3);
		putpixel(-x, y, 3);
		putpixel(-x, -y, 3);
		putpixel(-y, -x, 3);
		putpixel(y, -x, 3);
		putpixel(x, -y, 3);
		if (p<0) p+=2*x+3;
		else{
			p+= 2*x-2*y+5;
			y--;
		}
		x++;
	}
}

int main(){
	initwindow(500,500);
	Mcircle(100, 100, 100);
	getch();
	return 0;
}
