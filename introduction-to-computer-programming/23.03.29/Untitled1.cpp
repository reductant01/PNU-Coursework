#include <stdio.h>

int main()
{
	int num;
	
	printf("숫자를 입력하세요: ");
	scanf("%d",&num);
	
	if(num%2==0)
		printf("%d은(는) 짝수입니다\n",num);
	else
		printf("%d은(는) 홀수입니다\n",num);
	
}
