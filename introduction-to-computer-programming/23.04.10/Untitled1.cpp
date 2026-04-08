#include <stdio.h>
int main()
{
	int i, j;
	
	i=1;
	// j=1;을 여기에 쓰면 작동 안함 
	while(i<=10)
	{
		j=1;
		while(j<=11-i)
		{
			printf("#");
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
	
	for(i=1;i<=10;i++)
	{
		for(j=1;j<=11-i;j++) //j<=i, j<=10
			printf("#");
		printf("\n");
		
	}
	
}
