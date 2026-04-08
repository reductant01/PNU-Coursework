#include <stdio.h>

int main()
{
	int array[][3]={{10,20,30},{40,50,60}};  
	//int **p=array; , array를 정수형 배열로 두면 에러발생
	int *p=array[0]; //p를 1차원으로 알아들음 
	int i,j;
	
	for(i=0;i<6;i++)
		printf("*(p+%d)=%d\n",i,*(p+i));
	
 } 
