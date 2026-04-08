#include <stdio.h>
int main()
{
	int num;
	
	printf("숫자?");
	scanf("%d", &num);
	
	if(num%2==0) //%은 나머지를 구하는 연산자 
		printf("%d은(는) 짝수!", num);
	else
		printf("%d은(는) 홀수!", num);
			
	
}
