#include <stdio.h>
void x();

int main()
{
	int i;
	
	for(i=1;i<5;i++)
		x();
		
}

void x()
{
	static int n=1; //int n 은 지역변수, static int n 은 정적 지역 변수 
	
	printf("%2d",n++);
}
