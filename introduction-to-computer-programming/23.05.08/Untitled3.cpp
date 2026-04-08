#include <stdio.h>

int main()
{
	char str[][6]={"Korea","Japen","China","USA"};
	int i,j;
	
	for(i=0;i<4;i++)
		printf("%s\n",str[i]);
		
	printf("\n");
	
	for(i=0;i<4;i++)
	{
		for(j=0;j<6;j++)
			printf("str[%d][%d]=%c\n",i,j,str[i][j]);
		printf("\n");		
	}	
	
}
