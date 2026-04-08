#include <stdio.h>
int main()
{
	int n;
	
	//n값이 0미만이면 다시 입력받기 
	while(1)//무한루프 
	{
		printf("필요한 물건의 개수는?");
		scanf("%d",&n);
		
		if(n>=0)
			break; //for문이 아닌곳에 break사용시 에 러 
		printf("잘못된 정수를 입력했습니다.\n");	
		
	}
}
