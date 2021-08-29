#include <iostream>
#include <graphics.h>
using namespace std;

void vehinh(int x0,int y0)
{
	rectangle(x0,y0,x0+50,y0+30);
}

int main() {
	int x, y, tx, ty;
	cout << "Nhap toa do ve hinh \nx = ";
	cin >> x;
	cout << "y = ";
	cin >> y;
	initwindow(500, 500);
	vehinh(x, y);
	cout << "Tx = ";
	cin >> tx;
	cout << "Ty = ";
	cin >> ty;
	x += tx;
	y += ty;
	vehinh(x, y);
	getch();
	return 0;
}
