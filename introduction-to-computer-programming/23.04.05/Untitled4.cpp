#include <stdio.h>
int main()
{
	int i, sum=0;
	
	i=1;	//초기값 
	while(i<=100)	//조건식 
	{
		sum+=i;
		i++;	//증감식 
	}
	printf("1~100까지의 합:%d\n",sum);
	
}
