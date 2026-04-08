#include <stdio.h>

int addition(int n);

int main()
{
	int n;
	
	printf("1~n까지의 합 n? ");
	scanf("%d", &n);
	
	printf("1~%d까지의 합은 %d입니다.",n,addition(n));
	 
}

int addition(int n)
{
	int result;
	
	if(n>1)
		result=addition(n-1)+n;
	else
		result=1;
		
	return(result);	
}
