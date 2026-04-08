#include <stdio.h>
int main()
{
	int i, j, res;
	
	i=2;
	while(i<=9)
	{
		j=1;
		while(j<=9)
		{
			res=i*j;
			printf("%d x %d = %d\n",i,j,res);
			j++;		
		}
		printf("\n");
		i++;	
	}
	printf("ÇÑ¹ø´õ\n");
	
	for(i=2;i<=9;i++)
	{
		for(j=1;j<=9;j++)
		{
			res=i*j;
			printf("%d x %d = %d\n",i,j,res);
		}
		printf("\n");
	}
}
