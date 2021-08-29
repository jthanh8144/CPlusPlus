#include <stdio.h>
main(){
	int f;
	float c;
	for (f=0;f<=300;f+=20){
		c=5*(f-32)/9;
		printf("%5d F <-> %0.3f\n",f,c);
	}
}
