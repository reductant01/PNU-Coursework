#include <stdio.h>

int main()
{
	char *str[4]={"korea", "japen", "china", "usa"};
	int i,j;
	
	for(i=0;i<4;i++)
		printf("*(str+%d)=%s\n",i,*(str+i));
		
	printf("\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("*(*(str+%d)+%d)=%c\n",i,j,*(*(str+i)+j));
		}	
		printf("\n");
	}	
		
		
	
}
