#include <iostream>
#include <math.h>
#include <graphics.h>
#define FACT 1/sqrt(2)
#define PI 3.1415
#define RADS PI/180

void C(float dir, float len, int n){ 
	if (n  > 0){ 
		dir += 45.0;  
		C(dir, len*FACT, n-1); 
		dir -= 90.0;  
		C(dir, len*FACT, n-1); 
	} 
	else linerel(int(len*cos(dir*RADS)), int(len*sin(dir*RADS))); 
}

void C(int n, int a, int b, int c, int d){
	if (n>0){ 
		C(n-1, a, b, (a + c + b - d)/2, (b + d + c - a)/2); 
		C(n-1, (a + c + b - d)/2, (b + d + c - a)/2, c, d); 
	} 
	else line(a, b, c, d); 
}

int main() {
	initwindow(500, 500);
	C(-60, 100, 10);
	getch();
	return 0;
}
