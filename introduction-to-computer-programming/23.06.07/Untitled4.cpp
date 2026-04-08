#include <stdio.h>

int main()
{
	int array[][3]={{10,20,30},{40,50,60}};  
	//int **p=array; , array를 정수형 배열로 두면 에러발생
	int (*p)[3]=array; //p를 2차원 배열로 할당하는 방법! 
	int i,j;
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
			printf("*(*(p+%d)+%d)=%d\n",i,j,*(*(p+i)+j));
		printf("\n");	
	}
	
 } 
