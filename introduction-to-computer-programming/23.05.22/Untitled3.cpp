#include <stdio.h>
void x();

int n=10; //전역변수(외부변수) 

int main()
{
	
	x();
		
}

void x()
{
	int n=1; //지역변수(내부변수) 
	
	n=n+10;
	
	printf("n=%d",n); //내부변수와 외부변수가 충돌하면 내부변수가 우선(c언어 뿐만아니라 다른언어도 마찬가지) 
	
}
