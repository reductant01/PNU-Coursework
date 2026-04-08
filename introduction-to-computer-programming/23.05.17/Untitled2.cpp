#include <stdio.h>
#define N 4

void print_arr(int arr[N]);
void percentage(int arr[N]);

int main()
{
	int count[N]={42,37,83,33};
	
	printf("인원수: ");
	print_arr(count); 
	
	percentage(count);
	
	printf("\n백분율: ");
	print_arr(count);
	
	return 0;
}

void print_arr(int arr[N])
{
	int i;
	for(i=0;i<N;i++)
		printf("%3d",arr[i]);
	
}

void percentage(int arr[N])
{
	int i, total=0;
	
	for(i=0;i<N;i++)
		total += arr[i];
		
	for(i=0;i<N;i++)
		arr[i]=(int)((double)arr[i]/ total * 100);	
}
