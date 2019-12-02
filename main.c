#include <stdio.h>
#include "myBank.c"

int main()
{
    
	char input;
	do
	{
	printf(" to Opening an account and saving the initial deposit amount press O \n to Balance inquiry press B \n to Deposit money press D\n to cash withrawal press W \n to Account Closing press C \n to Add interest press I \n to Print accounts press P \n to Closing all accounts press E \n ");
	
		if(scanf("%1c",&input)==1)
		{
			switch(input)
			{
			case 'O':
			O();
			break;
		
			case 'B':
			B();
			break;
		
			case 'D':
			D();
			break;
		
			case 'W':
			W();
			break;
		
			case 'C':
			C();
			break;
			
			case 'I':
			I();
			break;
		
			case 'P':
			P();
			break;
		
			case 'E':
			E();
			break;
			
			default:
			printf("You typed an error. Try again /n ");
			break;
			}
		
		
		}
	}while (input != 'E');

	return 0;
		
}


