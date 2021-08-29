#include <iostream>
#include <math.h>
#include <graphics.h>
#define FACT 1/sqrt(2)
#define PI 3.1415
#define RADS PI/180

void Koch(float dir, float len, int n) {
	if (n> 0) {
		Koch (dir, len/3, n-1);
		dir += 60.0;
		Koch (dir, len/3, n-1);
		dir -= 120.0; 
		Koch (dir, len/3, n-1);
		dir += 60.0;
		Koch(dir, len/3, n-1);
	}
	else linerel(int(len*cos(dir *RADS)), int(len*sin(dir*RADS)));
}


void K(int n, int a, int b, int c, int d){   
	int u, v; 
	if (n > 0){ 
		u = int(a + (c - a)/2 + FACT*(d - b)/3);  
		v = int(b + (d - b)/2 + FACT*(a - c)/3); 
		K(n-1, a, b, a + (c - a)/3, b + (d - b)/3);   
		K(n-1, a + (c - a)/3, b + (d - b)/3, u, v); 
		K(n-1, u, v, a + 2*(c - a)/3, b + 2*(d - b)/3);
		K(n-1, a + 2*(c - a)/3, b + 2*(d - b)/3, c, d);
	} 
	else line(a, b, c, d); 
} 

int main() {
	initwindow(500, 500);
	Koch (0.0, 0.05, 3);
//	Koch (-120.0, 0.05, 3);
//	Koch (120.0, 0.05, 3);
//	K(5, 20, 20, 100, 100);
	getch();
	return 0;
}
