#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num1, num2;
	double res;
	char opr;
	
	printf("첫 번째 숫자: ");
	scanf("%d",&num1);
	
	printf("두 번째 숫자: ");
	scanf("%d",&num2);
	
	fflush(stdin);
	
	printf("연산자 : ");
	scanf("%c",&opr);
	
	switch(opr)
	{	
		case '+':
			res=num1+num2;
			printf("%d %c %d = %.0f\n",num1,opr,num2,res);
			break;
			
		case '-':
			res=num1-num2;
			printf("%d %c %d = %.0f\n",num1,opr,num2,res);
			break;
			
		case '*':
			res=num1*num2;
			printf("%d %c %d = %.0f\n",num1,opr,num2,res);
			break;
			
		case '/':
			if(num2==0)
			{
				printf("0으로 나눌 수 없습니다.");
				exit(0);
			} 
			else
			{
		
				res=(double)num1/(double)num2;
				printf("%d %c %d = %.1f\n",num1,opr,num2,res); 
				break;	
			}
		default:
			printf("연산자 오류!!\n");
	
	}
	
	/*
	if(opr=='+')
	{
		res=num1+num2;
		printf("%d %c %d = %.0f\n",num1,opr,num2,res);
	
	}
	else if(opr=='-')
	{
		res=num1-num2;
		printf("%d %c %d = %.0f\n",num1,opr,num2,res);
	
	}
	else if(opr=='*')
	{
		res=num1*num2;
		printf("%d %c %d = %.0f\n",num1,opr,num2,res);
	
	}
	else if(opr=='/')
	{
		if(num2==0)
		{
			printf("0으로 나눌 수 없습니다.");
			exit(0);
		} 
		else
		{
	
			res=(double)num1/(double)num2;
			printf("%d %c %d = %.1f\n",num1,opr,num2,res); 
		}
	}
	else
		printf("연산자 오류!!\n");
		
	*/

}
