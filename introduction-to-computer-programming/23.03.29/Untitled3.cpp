#include <stdio.h>
#include <stdlib.h> //exit함수를 사용하기 위함 

int main()
{
	int num1, num2;
	double res;
	char opr;//연산자를 저장
	
	printf("첫 번찌 숫자를 입력하세요:");
	scanf("%d",&num1); 
	
	printf("두 번찌 숫자를 입력하세요:");
	scanf("%d",&num2); 
	
	fflush(stdin); 
	
	printf("연산자를 입력하세요:");
	scanf("%c",&opr); 
	
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
			exit(0); //프로그램을 강제적으로 종료시킨다	
		} 
		else
		{
	
			res=(double)num1/(double)num2;
			printf("%d %c %d = %.1f\n",num1,opr,num2,res); //소수점 2에서 반올림 
		}
	}
	else
		printf("연산자 오류!!\n");
	
	printf("프로그램 종료\n"); 
	
}
