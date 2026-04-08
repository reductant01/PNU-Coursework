#include <stdio.h>
#define N 4

void print_arr(int *);
void percentage(int *,int *);

int percent[N];

int main()
{
	int count[N]={42,37,83,33};
	int i;
	
	printf("인원수: ");
	print_arr(count); 
	
	percentage(count,percent);
	
	printf("\n백분율: ");
	print_arr(count); 
	
	printf("\n배열의 내용: \n");
	for(i=0;i<N;i++)
		printf("percent[%d]=%d\n",i,percent[i]);
}


void print_arr(int*arr)
{
	int i;
	
	for(i=0;i<N;i++)
		printf("%3d",*(arr+i));
		
}

void percentage(int *arr, int *pct)
{
	int i, total=0;
	
	for(i=0;i<N;i++)
		total += *(arr+i);		
	
	for(i=0;i<N;i++)
		*(pct+i)=(int)((double)*(arr+i)/total*100);
		
}
