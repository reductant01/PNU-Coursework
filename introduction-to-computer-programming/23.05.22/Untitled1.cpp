#include <stdio.h>
void reverse(int n);

int main()
{
	int n;
	
	printf("n~1까지 출력 n? ");
	scanf("%d", &n);
	
	reverse(n);
}

void reverse(int n)
{
	printf("%3d",n);
	if(n>1)
		reverse(n-1);
		
	return;	
}
