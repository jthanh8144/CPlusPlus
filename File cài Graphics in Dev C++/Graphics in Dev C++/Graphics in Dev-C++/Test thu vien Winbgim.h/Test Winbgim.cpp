/*	Test thu vien winbgim.h	*/

#include <winbgim.h> 

main(int argc, char *argv[])
{
	initwindow(300, 300);					// init window graphics
	//setbkcolor(1);							// set background
	cleardevice();
	settextstyle(0,0,2);
	//setcolor(14);							// set text color
	outtextxy(50,100,"Graphics in Dev-C++");// print text in window graphics
	setcolor(15);
	line(20,20,620,20);
	while(!kbhit()) delay(1);				// pause screen	
}
