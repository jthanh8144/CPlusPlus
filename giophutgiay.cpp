#include <stdio.h>
main(){
	int h,m,s,n;
	printf("Nhap h, m, s, n: ");
	scanf("%d %d %d %d",&h,&m,&s,&n);
	h+=n/3600;
	m+=(n%3600)/60;
	s+=(n%3600)%60;
	if (s>59){
		m+=1;
		s-=60;
	}
	if (m>59){
		h+=1;
		m-=60;
	}
	if (h==24) h=0;
	if (h>24) h-=24;
	printf("ket qua: %d : %d : %d",h,m,s);
}
