//Textbook Rental System
//Author: Dana-Lee Powell
//Due Date: October 23,2018
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char password[25];
	printf("Enter the password please:\n");
	scanf("%s",&password);
if(strcmp(password,"danaleepowell")==0)
{
	printf("Password is correct!\n\n\n\n");
}
else
{
	do
	{
		printf("This password is incorrect\n");
		printf("Please enter the correct password:\n");
		
		scanf("%s", &password);
		
	}while(strcmp(password,"danaleepowell")!=0);
	
}
system("cls");
	int ISBN_num, rent_fee;
	char Bktitle[50], Bkcondition[15], Bksource[20];
	float Pur_amount;
	
	printf("WELCOME TO THE OFFICIAL TEXTBOOK RENTAL SYSTEM!!!");
	printf("\n\tEnter the ISBN of the book:");
	scanf("%d",&ISBN_num);
	printf("\nEnter the title of the book:");
	scanf("%s",&Bktitle);
	printf("\n");
	return 0;
}
