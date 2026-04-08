#include <stdio.h>
int main()
{
	int i, sum=0;
	
	/*for(i=1;;i++)
	{
		sum+=i;
		if(sum>=10)
			break;
	}*/
	
	for(i=0, sum=0; sum<10; sum+=i)
	{
		i++;
	}
	
	
	printf("합이 10이 넘었을 떄의 항:%d\n",i);
	printf("1~%d까지의 합: %d\n",i,sum);
	
	
}
