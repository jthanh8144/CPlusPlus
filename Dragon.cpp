#include <iostream>
#include <math.h>
#include <graphics.h>
#define FACT 1/sqrt(2)
#define RADS 3.14/180

void Dragon(float dir, float len, int n, int s){
	if (n  > 0) {
		dir += 45.0*s;    
    	Dragon (dir, len*FACT, n-1, 1);
		dir -= 90.0*s;   
    	Dragon (dir, len*FACT, n-1, -1);
	}
	else {
		setcolor(rand() % 5 + 13); 
    	linerel(int(len * cos(dir * RADS)), int(len * sin(dir * RADS))); 
	}
}

void D(int n, int a, int b, int c, int d){
	if (n>0){ 
		D(n-1, a, b, (a+c+b-d)/2, (b+d+c-a)/2); 
		D(n-1, c, d, (a+c+b-d)/2, (b+d+c-a)/2); 
	} 
	else line(a, b, c, d); 
}

int main() {
	initwindow(500, 500);
	Dragon(60, 300, 5, 3);
	getch();
	return 0;
}
