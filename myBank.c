#include<stdio.h>
#include "myBank .h"
#define SIZE 50


double mount [2][SIZE];


void O ()
{
	int temp = -1;
	int i;
	for( i = 0; i < SIZE; i++)
	{
		if(mount[0][i] == 0){
			temp = i;
			break;
					}
	}
	if (temp == -1)
	{
		printf("Unable to open account");
		return;
	}
	
	double amount = 0;
	printf("Enter money: ");
	if(scanf("%lf", &amount) == 1)
	{
		if(amount < 0)
		{
			printf("Unable to open account");
			return;
		}
		mount[0][temp] = 1;
		mount[1][temp] = amount;
		printf("The account number is %d \n", temp + 901);
		return;
	}
}

void B ()
{
	int temp;
	printf("Enter account number");
	if(scanf("%d", &temp) == 1)
	{
		if(temp<901 || temp>950)
		{
			printf("Bad account number");
			return;
		}
		if(mount[0][(temp-901)] != 0)
		{
			printf("Your balance is : %0.2lf", mount[1][temp-901]);
		}
		else
		{
			printf("This account does not exist");
		}
	}
	else
	{
		printf("Incorrect account number");
	}
	return;
}
	
void D ()
{
	int temp;
	printf("Enter an account number");
	if(scanf("%d",&temp)==1)
	{
		if (temp<901 || temp>950)
	{
	printf("No account exists");
	return;
	}
	if(mount[0][(temp-901)] == 1)
	{
	double Deposit;
	printf("Type a deposit amount");
	if(scanf("%lf",&Deposit)== 1)
	{
	if(Deposit<0)
	{
	printf("Deposit cannot be made");
	return;
	}
	mount[1][(temp-901)] = (((double)(mount[1][(temp-901)])) + (Deposit));
	mount[1][(temp-901)] = ((int) ((mount[1][(temp-901)])*100))/100.0;
	printf("Your balance is :  %0.2lf", (mount[1][(temp-901)]));
	return;
	}
	}
	}
	else
	{
		printf("The account does not exist");
	}
	return;
}

void W ()
{
	int temp;
	printf("Type an account number");
	if(scanf("%d", &temp)==1)
	{
		if (mount[0] [(temp - 901)]== 0)
		{
			printf("The account does not exist");
			return;
		}
		if (temp<901||temp>950)
		{
		printf("Incorrect account");
		return;
		}
		double sumofmoney;
		printf("The amount of money to withdraw : /n");
		if(scanf("%lf", &sumofmoney)==1)
		{
			if(sumofmoney<0)
			{
				printf("Unable to pull");
				return;
			}
			if (sumofmoney > (mount[1][temp-901]))
			{
				printf("You cannot withdraw a high amount");
				return;
			}
			mount[1][(temp-901)] = mount[1][(temp-901)] -sumofmoney ;
			(mount[1][(temp-901)]) = ((int)((mount[1][(temp-901)])*100))/100.0;
			printf("The balance is : %0.2lf", mount[1][(temp-901)]);
			return;
		}
	}
}
	
	void C ()
	{
		int temp;
		printf("Type your account number");
		if(scanf("%d",&temp)==1)
		{
			if (temp<901||temp>950)
			{
				printf("No account exists");
				return;
			}
			if (mount[0][(temp-901)]==0)
			{
				printf("No account exists");
				return;
			}
			mount[0][(temp-901)]=0;
			mount[1][(temp-901)]=0 ;
			printf("Account closed");
			return;
		}
		else
		{
			printf("Incorrect account number");
		}
	}
	
	void I ()
	{
		int insertbank;
		int i;
		printf("What is the percentage of interest? /n");
		if(scanf("%d",&insertbank)==1)
		{
			if(insertbank<0)
			{
				printf("Incorrect interest");
				return;
			}
		for(i=0;i<SIZE;i++)
		{
			(mount[1][i]) =  (mount[1][i]) + ((mount[1][i])*(insertbank/100.0));
			(mount[1][i]) = ((int)((mount[1][i])*100))/100.0;
		}
		printf("The action was successful");
		}
		else
		{
			printf("Incorrect interest");
		}
	}
	
	void P ()
	{
		double nummount;
		double money;
		int i;
			for( i=0; i<SIZE; i++) 
			{
				double nummount=(i + 901);
				money=mount[i][1];
				if (mount[0][i]==1)
				{
					printf("Account number = %0.0lf \n The money in the account = %0.2lf\n\n",nummount,money);
				}
			}
			return;
	}
	
	void E ()
	{
		int i;
		for(i=0; i<SIZE ;i++)
		{
			mount[0][i] = 0;
			mount[1][i] = 0;
		}
		printf("The action was successful");
		return;
	}
	
	
	
