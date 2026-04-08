#include <stdio.h>
//void swap(int *, int *);
void swap(int , int );

int main()
{
	int num1, num2;
	
	printf("두 수를 입력하세요? ");
	scanf("%d%d",&num1,&num2);
	
	printf("===함수 호출 전 ===\n");
	printf("num1=%d, num2=%d\n",num1,num2);
	
	//swap(&num1, &num2);
	swap(num1, num2);
	
	printf("\n===함수 호출 후 ===\n");
	printf("num1=%d, num2=%d\n",num1,num2);
	
	
	
}

/*void swap(int *n1, int *n2)
{
	int temp;
	
	temp=*n1;
	*n1=*n2;
	*n2=temp;
}*/
void swap(int n1, int n2)
{
	int temp;
	
	temp=n1;
	n1=n2;
	n2=temp;
}
