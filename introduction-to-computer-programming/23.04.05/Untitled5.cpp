#include <stdio.h>
int main()
{
	int i, sum=0;
	
	i=1;
	while(sum<=1000)
	{
		sum+=i++;
	}
	printf("1~%d까지의 합:%d\n",i-1,sum);
	
}
