#include <stdio.h>
int main()
{
	int i, n, sum;
	
	while(1)
	{
		printf("정수를 입력하세요: ");
		scanf("%d",&n);
		
		if(n==-1)
			break;
		
		sum=0;	
		for(i=1;i<=n;i++)
			sum+=i;
		printf("1~%d까지의 합은 %d\n",n,sum);
				
	} 
	printf("프로그램 종료!\n");
}
