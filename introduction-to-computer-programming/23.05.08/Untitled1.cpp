#include <stdio.h>

int main()
{
	int a[5];
	int i, j, temp; 
	
	for(i=0;i<5;i++)
	{
		printf("%d번째 숫자 : ",i+1);
		scanf("%d",a+i); //scanf("%d",&a[i]);		
	}
	//정렬 전 배열의 내용 출력 
	printf("\n");
	for(i=0;i<5;i++)
		printf("a[%d]=%d\n",i,a[i]);
	
	for(i=0;i<5;i++)//행 정렬의 단계 
	{
		for(j=0;j<5;j++)//열 교환의 횟수 
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;	
			}	
		}
	}	
	
	//정렬 후 배열의 내용 출력 
	printf("\n");
	for(i=0;i<5;i++)
		printf("a[%d]=%d\n",i,a[i]);
		
}
