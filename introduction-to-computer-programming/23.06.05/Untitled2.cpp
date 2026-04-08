#include <stdio.h>
#define SIZE 5

int main()
{
	int i, arr[SIZE]={10,20,30,40,50};
	int *ptr;
	
	ptr=arr;
	
	for(i=0;i<SIZE;i++)
		printf("arr[%d]=&d\n",i,arr[i]);
		
	printf("\n");
	
	printf("arr=%X, atr=%X\n", arr,ptr); //배열과 포인터의 주소 
	
	for(i=0;i<SIZE;i++)
		printf("*(arr+%d)=*(%X)=%d\n", i,arr+i,*(arr+i));
		
	printf("\n");	
		
	for(i=0;i<SIZE;i++)
		printf("ptr[%d]=%d\n",i,ptr[i]);	
}
