#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int i, random;
	int array[5];
	
	srand(time(NULL));
	
	/*for(i=1;i<=5;i++)
	{
		random=rand();
		printf("%d번째 난수 : %5d\n",i,random);
	}*/
	
	for(i=0;i<5;i++)
	{
		random=rand()%(20-10+1)+10;
		array[i]=random;
	}
	
	for(i=0;i<5;i++)
		printf("array[%d]=%d\n",i,array[i]);
}
