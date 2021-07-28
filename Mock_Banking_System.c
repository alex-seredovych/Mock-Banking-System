/*
 * 						Purpose: Development of a basic banking system that a regular user would use
 */

#include <stdio.h>
#include <stdlib.h> /* strtod*/
#include <stdbool.h>
#include<string.h>

#define MAXX 256

enum MenuItems { OPTIONS = 0, DEPOSIT=1, WITHDRAW=2, BALANCE=3, SUPPORT=4, CHANGEF=5, CHANGEL=6, CHANGEADDY=7, ACCOUNTNUM=8, FIRSTNAME=9, LASTNAME=10, VIEWADDY=11, OPT12=12, VIEWALL=13, QUIT=14};//Readability
 //Function Prototypes

bool securityCheck(const char *enteredAccountNumber, const char *enteredPasscode, const char *realAccountNumber, const char *realPasscode);

void printMyAccountNumber();
void printMyFirstName();
void printMyLastName();
void printMyAddress();

void printCurrentBalance();
void printAllInformation();
void deposit();
void withdraw();
void customerSupport();
void changeFirstName();
void changeLastName();
void changeAddress();


int main(void)
{

    char enteredAccountNumber[20];
    char enteredPasscode[20];
    char realAccountNumber[] = "6423";
    char realPasscode[] = "pass";
    bool loginCheck=false;
    printf("You have 3 attemts to access this account: \n"); 
    for(int i=0;i<3;i++){
    	printf("Enter account number: "); 
    	scanf("%s", enteredAccountNumber);
    	printf("Enter passcode: ");
    	scanf("%s", enteredPasscode);
    	if(securityCheck(enteredAccountNumber, enteredPasscode, realAccountNumber,  realPasscode)){//calls function that checks whether the information is correct
		loginCheck=true;
		break;
    	}
    	printf("Wrong, try again.\n");
    }
    
    if(loginCheck){//if login is true user gets access to the account
	    //char confirm;
	    enum MenuItems menuSelect;

	    printf("----------------Welcome Bank Employee----------------");
	    printf("\n\nEnter 0 to see a list of available actions:\n");

	    bool login = true;
	    char confirm;
	    
	    printf("\nUser %s is logged in", realAccountNumber);

	    while (login)//todo will allow access after above is implemented.
	    {
		    printf("\nWhat function is needed?: ");
		    scanf("%d", &menuSelect);

		    switch (menuSelect)
		    {
		    case OPTIONS:
			printf("OPTIONS--0\n");//done 
			printf("Deposit --1\n");//done
			printf("Withdraw --2\n");//done
			printf("Get my current balance --3\n");//done
			printf("Support number --4\n");
			printf("Change my First name --5\n");
			printf("Change my Last name --6\n");
			printf("Change my address --7\n");
			printf("See my account number --8\n");
			printf("See my first name --9\n");
			printf("See my last name --10\n");
			printf("See my address --11\n");
			printf("See locations of the banks nearby --12\n");
			printf("Print all information about my account--13\n");
			printf("EXIT--14\n");
			break;
			
			case DEPOSIT:
			deposit();
			break;
			
		    case WITHDRAW:
			withdraw();
			break;
			
		    case BALANCE:
		    	printCurrentBalance();
			break;
			
		    case SUPPORT:
		    	customerSupport();
			break;
			
		    case CHANGEF:
		    	changeFirstName();
			break;
			
		    case CHANGEL:
		    	changeLastName();
			break;
			
		    case CHANGEADDY:
		    	changeAddress();
			break;
			
		    case ACCOUNTNUM:
		    	printMyAccountNumber();
			break;  
			
		    case FIRSTNAME:
		    	printMyFirstName();
			break;
			
		    case LASTNAME:
		    	printMyLastName();
			break;
			
		    case VIEWADDY:
			printMyAddress();
			break;
			
		    case OPT12:
			break;
			
		    case VIEWALL:
		    	printAllInformation();
			break;
			
		    case QUIT:
			printf("confirm you want to quit(y/n): ");
			scanf(" %c", &confirm);//must leave space in front of %c will not work properly without//scanf for other compiler
			if (confirm == 'y')
			{
			    login = false;
			}
			printf("Thanks for using our program! Have a nice day!\n");
			break;  
		    
		    default:
			printf("Invalid input!\nEnter 0 to see available actions\n");
			break;
		    }//end switch



	    }//end inner while


    }
    else
    	printf("Sorry, but the information you entered is incorrect.\n");
    	
   
    
    
    return 0;
}//end main

 //Function Definitions

bool securityCheck(const char *enteredAccountNumber, const char *enteredPasscode, const char *realAccountNumber, const char *realPasscode){
	bool access = true;
	for ( ; *enteredAccountNumber!= '\0' && *realAccountNumber != '\0'; ++enteredAccountNumber, ++realAccountNumber ) 
	{
		if ( *enteredAccountNumber != *realAccountNumber ) 
		{
			return false;
		} // end if
	} // end for
	for ( ; *enteredPasscode!= '\0' && *realPasscode != '\0'; ++enteredPasscode, ++realPasscode ) 
	{
		if ( *enteredPasscode != *realPasscode ) 
		{
			return false;
		} // end if
	} // end for
	return access;

	
}

void printMyAccountNumber(){
	int counterLine=0;
	int k=0;
	char *accountNumber = NULL;
	int l = 0;
	int d;
	
	FILE *file = fopen("Banking_Account_Information.txt", "r");
	if(file == NULL)
	{
		printf("File can't be found.");
		exit(0);
	}
	
	while((d = getline(&accountNumber, &l, file)) != -1)
	{
		if(counterLine == k)
		{
			printf("Account number: %s", accountNumber);	
			fclose(file);
			break;
		}
		k++;
		
	}

}///end of print account number 

void printMyFirstName(){
	int counterLine=1;//first name is located on the line of index 1
	int k=0;
	char *firstName = NULL;
	int l = 0;
	int d;
	
	FILE *file = fopen("Banking_Account_Information.txt", "r");
	if(file == NULL)
	{
		printf("File can't be found.");
		exit(0);
	}
	
	while((d = getline(&firstName, &l, file)) != -1)
	{
		if(counterLine == k)
		{
			printf("First name: %s", firstName);	
			fclose(file);
			break;
		}
		k++;
		
	}
}// end of function getfirst name

void printMyLastName(){
	int counterLine=2;//first name is located on the line of index 1
	int k=0;
	char *lastName = NULL;
	int l = 0;
	int d;
	
	FILE *file = fopen("Banking_Account_Information.txt", "r");
	if(file == NULL)
	{
		printf("File can't be found.");
		exit(0);
	}
	
	while((d = getline(&lastName, &l, file)) != -1)
	{
		if(counterLine == k)
		{
			printf("Last name: %s", lastName);	
			fclose(file);//close file when finished
			break;
		}
		k++;//iterate through lines
		
	}//end of while loop 
}//end of function print last name 

void printMyAddress(){
	int counterLine=3;//Address is located on the line of index 3
	int k=0;
	char *address = NULL;
	int l = 0;
	int d;
	
	FILE *file = fopen("Banking_Account_Information.txt", "r");
	if(file == NULL)
	{
		printf("File can't be found.");
		exit(0);
	}
	
	while((d = getline(&address, &l, file)) != -1)
	{
		if(counterLine == k)
		{
			printf("Address: %s", address);	
			break;
		}
		k++;
		
	}
	fclose(file);
}

void printCurrentBalance(){
	int counterLine=4;//Balance is located on the line of index 4
	int k=0;
	char *balance = NULL;
	int l = 0;
	int d;
	
	FILE *file = fopen("Banking_Account_Information.txt", "r");
	if(file == NULL)
	{
		printf("File can't be found.");
		exit(0);
	}
	
	while((d = getline(&balance, &l, file)) != -1)
	{
		if(counterLine == k)
		{
			printf("Current Balance is: %s", balance);	
			fclose(file);
			break;
		}//S
		k++;
		
	}
	
	
}

void deposit(){
	int counterLine=4;//Balance is located on the line of index 4
	int k=0;
	char *balance = NULL,c;
	char sentence[256], res[100];
	int l = 0;
	int d;
	double Dbalance,newBalance, depAmount;
	
	printf("Enter the Deposit amount: ");
	scanf("%lf", &depAmount) ;
	
	FILE *file = fopen("Banking_Account_Information.txt", "r+");
	FILE *fTemp =fopen("Temp.txt","w");//
	
	if(file == NULL)
	{
		printf("File can't be found.");
		exit(0);
	}
	
	while((d = getline(&balance, &l, file)) != -1)
	{
		if(counterLine == k)
		{
			printf("\nCurrent Balance is: %s", balance);	
			Dbalance =atof(balance);
			newBalance =depAmount+Dbalance;
			printf("\nNew Balance after deposit is: %.2lf", newBalance);
			
		}//end if
		k++;
		
	}//end while 
	k=0;//reset k
	
	rewind(file);
	while(!feof(file))
	{
		strcpy(sentence,"\0");  //reads line until
		fgets(sentence,256,file);//reads in line max length of 256 chars
	
			
			if (k!=counterLine)
			{
				fprintf(fTemp, "%s",sentence);
			
			}//end if 
			else
			{
				sprintf(res,"%.2lf",newBalance); //converts float to string     newBalance is double, res is location of string and 2 is precision after decimal to keep 
			
				 fprintf(fTemp, "%s",res);
				 //fputs(fTemp,"\n ");//prevents final line from being deletedby adding a new line...unable to track down particular bug that deletes final line
			}
			k++;
			
	}//end of while
	if (k<7)
	{
		fprintf(fTemp, "\n",NULL);//print blank line to file prevents last line form being deleted
	}
	fclose(file);
	fclose(fTemp);
	remove(file);
	rename("Temp.txt", "Banking_Account_Information.txt");
	//printf("\nreached");
}//end of make deposit function

void withdraw(){
	int counterLine=4;//Balance is located on the line of index 5
	int k=0;
	char *balance = NULL,c;
	char sentence[256], res[100];
	int l = 0;
	int d;
	double Dbalance,newBalance, withdrawAmount;
	
	printf("\nEnter the withdraw Amount: ");
	scanf("%lf", &withdrawAmount) ;
	
	FILE *file = fopen("Banking_Account_Information.txt", "r+");
	FILE *fTemp = fopen("Temp.txt","w");
	
	if(file == NULL)
	{
		printf("File can't be found.");
		exit(0);
	}
	
	while((d = getline(&balance, &l, file)) != -1)
	{
		if(counterLine == k)
		{
			printf("\nCurrent Balance is: %s", balance);	
			Dbalance =atof(balance);
			newBalance =Dbalance-withdrawAmount;
			printf("\nNew Balance after Withdraw is: %.2lf", newBalance);
			
		}//end if
		k++;
		
	}//end while 
	k=0;//reset k
	
	rewind(file);
	while(!feof(file))
	{
		strcpy(sentence,"\0");  //reads line until
		fgets(sentence,256,file);//reads in line max length of 256 chars
		
			
			if (k!=counterLine)
			{
				fprintf(fTemp, "%s",sentence);
			
			}//end if 
			else
			{
				sprintf(res,"%.2lf",newBalance); //converts float to string     newBalance is double, res is location of string and 2 is precision after decimal to keep 
			
				 fprintf(fTemp, "%s",res);
				//fputs(fTemp,"\n ");//prevents final line from being deletedby adding a new line...unable to track down particular bug that deletes final line causes seg fault
			}
			k++;
					
	}//end of while
	if (k<7)
	{
		fprintf(fTemp, "\n",NULL);//print blank line to file prevents last line form being deleted
	}
	fclose(file);
	fclose(fTemp);
	remove(file);
	rename("Temp.txt", "Banking_Account_Information.txt");
	//printf("\nreached");
}//end of withdrawl


void printAllInformation()
{
	printMyAccountNumber();
	printMyFirstName();
	printMyLastName();
	printMyAddress();	
	printCurrentBalance();
	
}//end of print all function


void customerSupport()
{
	printf("\n For Assistance please call 1-800-BNK-HELP\ndisclaimer unsure if this is a real number\n");
}

void changeFirstName()
{
	printMyFirstName();//print verify current first name 

	int counterLine=1;//Balance is located on the line of index 5
	int k=0;
	char *firstName = NULL;
	int l = 0;
	int d;
	char sentence[256], res[100];
	
	printf("\nEnter New First Name: ");
	scanf("%s", &res) ;
	
	FILE *file = fopen("Banking_Account_Information.txt", "r+");
	FILE *fTemp = fopen("Temp.txt","w");
	
	if(file == NULL)
	{
		printf("File can't be found.");
		exit(0);
	}
	
	rewind(file);
	while(!feof(file))
	{
		strcpy(sentence,"\0");  //reads line until
		fgets(sentence,256,file);//reads in line max length of 256 chars
			if (k!=counterLine)
			{
				fprintf(fTemp, "%s",sentence);
			
			}//end if 
			else
			{
				//printf("\nreached11");
				fprintf(fTemp, " %s\n",&res);
				
			}
			k++;
					
	}//end of while
	if (k<7)
	{
		fprintf(fTemp, "\n",NULL);//print blank line to file prevents last line form being deleted
	}
	
	fclose(file);
	fclose(fTemp);
	remove(file);
	rename("Temp.txt", "Banking_Account_Information.txt");
	//printf("\nreached");
}//end of rename First

void changeLastName()
{
	printMyLastName();//print verify current last name 

	int counterLine=2;//Last name on line 2 
	int k=0;
	char *lastName = NULL;
	int l = 0;
	int d;
	char sentence[256], res[100];
	
	printf("\nEnter New Last Name: ");
	scanf("%s", &res) ;
	
	FILE *file = fopen("Banking_Account_Information.txt", "r+");// information source file 
	FILE *fTemp = fopen("Temp.txt","w");//open temporary file for information transfer
	
	if(file == NULL)
	{
		printf("File can't be found.");
		exit(0);
	}
	
	rewind(file);
	while(!feof(file))
	{
		strcpy(sentence,"\0");  //reads line until
		fgets(sentence,256,file);//reads in line max length of 256 chars
		
			
			if (k!=counterLine)
			{
				fprintf(fTemp, "%s",sentence);
			}//end if 
			else
			{
				//printf("\nreached11");
				fprintf(fTemp, "%s\n",&res);
			}
			k++;//indexing
					
	}//end of while
	
	if (k<8)
	{
		fprintf(fTemp, "\n",NULL);//print blank line to file prevents last line form being deleted
	}
	fclose(file);
	fclose(fTemp);
	remove(file);
	rename("Temp.txt", "Banking_Account_Information.txt");
	//printf("\nreached");
}//end of rename Last

void changeAddress()
{
	printMyAddress();//print verify current Address

	int counterLine=3;//Current address on line 3 
	int k=0;
	char *lastName = NULL;
	int l = 0;
	int d;
	char sentence[256], res[100];
	
	printf("\nEnter New Address: ");
	scanf(" %[^\n]s", &res) ;
	printf("%s",res);
	//exit(0);
	FILE *file = fopen("Banking_Account_Information.txt", "r+");
	FILE *fTemp = fopen("Temp.txt","w");
	
	if(file == NULL)
	{
		printf("File can't be found.");
		exit(0);
	}
	
	rewind(file);
	while(!feof(file))
	{
		strcpy(sentence,"\0");  //reads line until
		fgets(sentence,256,file);//reads in line max length of 256 chars
		
			
			if (k!=counterLine)
			{
				fprintf(fTemp, "%s",sentence);
			}//end if 
			else
			{
				//printf("\nreached11");
				fprintf(fTemp, "%s\n",&res);
			}
			k++;
					
	}//end of while continues copy until end of file 
	
	if (k<8)
	{
		fprintf(fTemp, "\n",NULL);//print blank line to file prevents last line form being deleted
	}
	
	fclose(file);
	fclose(fTemp);
	remove(file);
	rename("Temp.txt", "Banking_Account_Information.txt");
	//printf("\nreached");
}//end of Change address
