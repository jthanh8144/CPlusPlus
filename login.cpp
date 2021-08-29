#include <stdio.h>
#include <string.h>
#include <conio.h>
typedef struct user{
	char Email[20];
	char Name[20];
	char Password[20];
} User;

 
main()
{
	printf("\n ----------- Login ----------");
	printf("\n Email: ");
	User user;
	scanf("%s",&user.Name);
	printf("\n Password: ");
	char pass[20],email[20],password[20];
	pass[0] = getch();
	int i=0;
	while(pass[i] != 13 )
	{
		printf("*");
		pass[i]= getch();
	};
	printf("\n Processing...");
	FILE *f;
	f = fopen("D:\\DACS\\account.txt", "r");
	if (f == NULL) printf("\n File is not exist");
	do
	{
		fscanf(f,"%s %s",&email , &password);
		printf("\n %s %s",email,password);
		if(strcmp(user.Email,email) == 0 && strcmp(pass,password)== 0)
			printf("\n You already login");
		else printf("\n Password or Email incorrect ! Please try");
	} while( email == NULL );
	fclose(f);
	
}
