#include <stdio.h>

int main()
{
	int num;
	
	printf("숫자를 입력하세요");
	scanf("%d",&num);
	
	switch(num%2)
	{
		case 0:
		{ //c언어에서는 이경우 괄호 쓰지않음, 지금은 c++이기에 돌아감 
			printf("%d:짝수",num);
			break; 
		}
		case 1:
			printf("%d:홀수",num);	
			break; 
			
	}
	
}
