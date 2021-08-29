#include <stdio.h>
main(){
	int m,n,p,q;
	long s=0;
	for (m=1;m<10;m++)
		for (n=0;n<10;n++)
			for (p=0;p<10;p++)
				for (q=1;q<10;q++){
					printf("%d%d.%d%d ",m,n,p,q);
					s+=1;
				}
	printf("Co %d so thoa de bai!",s);
}
