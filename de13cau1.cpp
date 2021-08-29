#include <stdio.h>
main(){
	long long a,i=0,n[100000],m,kt=0;
	printf("Nhap a = ");
	scanf("%ld",&a);
	while (a/10!=0){
		n[i]=a%10;
		i++;
		a/=10;
	}
	n[i]=a;
	m=i+1;
	for (i=0;i<m/2;i++)
		if (n[i]==n[m-i-1]) kt+=1;
	if (kt==m/2) printf("So da nhap la so tu doi xung.");
	else printf("So da nhap khong phai la so tu doi xung.");
}
