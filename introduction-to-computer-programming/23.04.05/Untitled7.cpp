#include <stdio.h>
int main()
{
	int dan, num, res;
	
	for(dan=2; dan<=9; dan++)
	{
		for(num=1; num<=9; num++)
		{
			res=dan*num;
			printf("%d x %d = %d\n",dan,num,res);
		}
		printf("\n");
	}
}
