#include <stdio.h>
long c(int k, int n){
	if (k==0||k==n) return 1;
	if (k==1) return n;
	return c(k-1,n-1)+c(k,n-1);
}
main(){
	long k,n;
	printf("Nhap n = ");
	scanf("%d",&n);
	printf("Nhap k =");
	scanf("%d",&k);
	printf("%d C %d = %d\n",n,k,c(k,n));
	for (int i=0;i<n;i++){
		for (int j=0;j<=i;j++)
			printf("%d ",c(j,i));
		printf("\n");
	}
}
