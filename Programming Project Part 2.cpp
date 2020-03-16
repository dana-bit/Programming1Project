#include  <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
int main()
{
	int options, ISBN_num[10];
	int i=0,p, Update, found, Search;
	char password[20];
	char Bk_condition[10][10];
	float pur_amount[10];
	float rent_fee=0; 	
	float Total_amt=0;
	float Total_rent=0;
	
	for(i = 0; i <= 9; i++)
		ISBN_num[i] = -1;
		
	system("color B0");
	
	do
	{
		printf("\t\t\t******************************************************");
		printf("\n\t\t\t*WELCOME TO THE OFFICIAL TEXTBOOK INVENTORY SYSTEM!!!*");
		printf("\n\t\t\t******************************************************");
		printf("\n\t\t\t******************************************************");
		printf("\n");
		printf("\t\t\tPlease enter password(3 attempts):\n\t\t\t");
		scanf("%s", password);
		p=3;
		while(strcmp(password,"PASSword12")!=0)
		{
			if(p<2)
			{
				printf("\n\t\t\tCannot enter anymore!!");
				exit(0);
			}
			p--;
			printf("\n\t\t\tPassword is incorrect!\t\t\t ");
			printf("\n\t\t\tEnter correct password:\n\t\t\t");
			scanf("%s", password);
		}
	
	
		do
		{
			system("cls");
			printf("\t\t\t******************************************************");
			printf("\n\t\t\t*WELCOME TO THE OFFICIAL TEXTBOOK INVENTORY SYSTEM!!!*");
			printf("\n\t\t\t******************************************************");
			printf("\n\t\t\t******************************************************");
			printf("\n");
			printf("\n\t\t\t\t\tOPTIONS:");
			printf("\n\t\t\t1: Add a book");
			printf("\n\t\t\t2: Update a book");
			printf("\n\t\t\t3: Display Totals");
			printf("\n\t\t\t0: Exit Program");
			printf("\n\t\t\tSelect what you would like to do:\n");
			printf("\n\t\t\t");
			scanf("%d",&options);
			system("cls");
	
			switch(options)
			{
				case 1:
					printf("\t\t\t***************************************\n");
					printf("\t\t\tOPTION 1: ADD A BOOK\n");
					printf("\t\t\t***************************************\n");
					found = 0;
					i = 0;
					while(found == 0 && i <= 9)
						if(ISBN_num[i] == -1)
							found = 1;
						else
							i++;	
	
					if(found == 1)
					{
						printf("\n\t\t\t>Enter ISBN number(0 to return to menu):\n\t\t\t#");
						scanf(" %d", &ISBN_num[i]);
						if(ISBN_num[i]== 0){
								ISBN_num[i] = -1;
								system("cls");
						}
						else
						{
							printf("\n\t\t\t>Enter the book condition(Excellent,Fair or Good):\n\t\t\t");
							scanf("%s",&Bk_condition[i] );
							while(strcmp(Bk_condition[i],"Excellent")!=0 && strcmp(Bk_condition[i],"Good")!=0 && strcmp(Bk_condition[i],"Fair")!=0)
							{
								printf("\t\t\tInvalid book condition!!\n\t\t\t Please re-enter:");
								scanf("%s",&Bk_condition[i]);
							}
							printf("\n\t\t\tEnter price of the book(no more than $3000):\n\t\t\t$");
							scanf("%f", &pur_amount[i]);
							while (pur_amount[i]>3000)
							{
								printf("\n\t\t\tThat book is too expensive!\n");
								printf("\t\t\tPlease re-enter:\n\t\t\t$");
									scanf("%f", &pur_amount[i]);
							}
							if(strcmp(Bk_condition[i],"Excellent")==0)
								rent_fee= pur_amount[i]* 0.2;				
							else
								if(strcmp(Bk_condition[i],"Good")==0)
									rent_fee= pur_amount[i]*0.15;
								else
									if(strcmp(Bk_condition[i], "Fair")==0)
										rent_fee=pur_amount[i]*0.8;
		
							printf("\n\t\t\tYour estimated Rental fee:\n\t\t\t$%.2f\n",rent_fee);
							printf("\n\t\t\tThank you for adding a book!!\n\n");	
							system("pause");
							system("cls");
						}
					}
					else
						printf("You cannot enter anymore books!\n");
					break;
				case 2:
					printf("\n\t\t\t**********************************\n");
					printf("\t\t\tOPTION 2: UPDATE A BOOK\n");
					printf("\n\t\t\t**********************************\n");
					printf("\t\t\t>Enter ISBN number:\n\t\t\t#");
					
					scanf(" %d", &Search);
					found = 0;
					i = 0;
					while(found == 0 && i <= 9)
						if(Search == ISBN_num[i])
							found = 1;
						else
							i++;	
					if(found == 1)
					{
						printf("\n\t\t\t\t******BOOK INFORMATION******");
						printf("\n\t\t\tCondition:%s",Bk_condition[i]);
						printf("\n\t\t\tPurchase Price:$%.2f\n\n",pur_amount[i]);
						printf("\t\t\t>Select Options:\n");
						printf("\t\t\t1.Update Condition.\n\t\t\t2.Update Purchase Amount.\n\t\t\t3.Both\n\t\t\t");
						printf(">Select the one you would like to update:\n\t\t\t");
						scanf("%d",&Update);
						system("cls");
						
						if(Update==1){
							printf("\n\t\t\t>Enter the book condition(Excellent,Fair or Good):\n\t\t\t");
							scanf("%s",&Bk_condition[i] );
							while(strcmp(Bk_condition[i],"Excellent")!=0 && strcmp(Bk_condition[i],"Good")!=0 && strcmp(Bk_condition[i],"Fair")!=0)
							{
								printf("\n\t\t\tInvalid book condition.\n\t\t\tPlease re-enter:\n\t\t\t");
								scanf("%s",&Bk_condition[i]);
							}
						}
						
						if(Update==2){
							printf("\t\t\t>Enter price of the book(no more than $3000):\n\t\t\t");
							scanf("%f", &pur_amount[i]);
							while (pur_amount[i]>3000)
							{
								printf("\t\t\tThat book is too expensive! \n");
								printf("\t\t\tPlease re-enter:\n\t\t");
								scanf("%f", &pur_amount[i]);
							}
							if(strcmp(Bk_condition[i],"Excellent")==0)
								rent_fee= pur_amount[i]* 0.2;
							else
								if(strcmp(Bk_condition[i],"Good")==0)
									rent_fee= pur_amount[i]*0.15;
								else
									if(strcmp(Bk_condition[i], "Fair")==0)
										rent_fee=pur_amount[i]*0.8;
						}
						
						if (Update==3){
							printf("\n\t\t\t>Enter the book condition(Excellent,Fair or Good):\n\t\t\t");
							scanf("%s",&Bk_condition[i] );
							while(strcmp(Bk_condition[i],"Excellent")!=0 && strcmp(Bk_condition[i],"Good")!=0 && strcmp(Bk_condition[i],"Fair")!=0)
							{
								printf("\n\t\t\tInvalid book condition.\n\t\t\tPlease re-enter:\n\t\t\t");
								scanf("%s",&Bk_condition[i]);
							}
							
							printf("\t\t\t>Enter price of the book(no more than $3000):\n\t\t\t");
							scanf("%f", &pur_amount[i]);
							while (pur_amount[i]>3000)
							{
								printf("\t\t\tThat book is too expensive! \n");
								printf("\t\t\tPlease re-enter:\n\t\t");
								scanf("%f", &pur_amount[i]);
							}
							if(strcmp(Bk_condition[i],"Excellent")==0)
								rent_fee= pur_amount[i]* 0.2;
							else
								if(strcmp(Bk_condition[i],"Good")==0)
									rent_fee= pur_amount[i]*0.15;
								else
									if(strcmp(Bk_condition[i], "Fair")==0)
										rent_fee=pur_amount[i]*0.8;
						}
						printf("\n\t\t\t******BOOK UPDATED******\n");
						printf("\n\t\t\tISBN number:%d",ISBN_num[i]);
						printf("\n\t\t\tCondition:%s",Bk_condition[i]);
						printf("\n\t\t\tPurchase Price:$%.2f\n",pur_amount[i]);
						system("pause");
						system("cls");
					}else 
						{
							printf("\t\t\tNOT FOUND\n");
							system("pause");
							system("cls");
						}
					break;
				case 3:
					printf("\n\t\t\t********************************************************");
					printf("\n\t\t\t\t\tOPTION 3: DISPLAY TOTALS");
					printf("\n\t\t\t********************************************************\n");	
					i = 0;
					while(ISBN_num[i] != -1)
					{
						printf("\t\t\t\t\t******BOOK REPORT******\n");
						printf("\n\t\t\tISBN: %d", ISBN_num[i]);
						printf("\n\t\t\tCondition:%s",Bk_condition[i]);
						printf("\n\t\t\tPurchase Price:$%.2f",pur_amount[i]);
						if(strcmp(Bk_condition[i],"Excellent")==0)							
								rent_fee= pur_amount[i]* 0.2;
							else
								if(strcmp(Bk_condition[i],"Good")==0)
									rent_fee= pur_amount[i]*0.15;
								else
									if(strcmp(Bk_condition[i], "Fair")==0)
										rent_fee=pur_amount[i]*0.8;
						Total_amt+=pur_amount[i];
						Total_rent+=rent_fee;
						printf("\n\t\t\tRental fee:$%.2f\n",rent_fee);
						printf("\n\t\t\t***********************************************************\n");
						i++;
					}
						printf("\n\t\t\tTotal Textbook Entered\t\t");
						printf("\n\t\t\tTotal Purchase Amount:$%.2f\t\t",Total_amt);
						printf("\n\t\t\tTotal Rental fee:$%.2f\t\t", Total_rent);
					system("PAUSE");
					break;
			}
		}while(options!=0);
	}while(strcmp(password,"PASSword12")==0);
}
