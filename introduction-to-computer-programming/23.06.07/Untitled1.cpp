#include <stdio.h>
#include <ctype.h>  //toupper, tolower 함수 
#include <string.h>

int main()
{
	char s[100],*p;
	int i;
	
	printf("문자열을 입력하세요: ");
	gets(s);
	
	p=s;
	
	while(*p!='\0')
	{
		*p=toupper(*p); //대문자로 변환시키는 함수 
		p++;	//여기서 p+i가 아닌 p값을 증가시켰으므로 p를 출력하면 아무값도 안나옴 
	}
	
	printf("\n대문자로 변환한 결과: %s\n",s); //s를 출력하는것 확인!, p를 출력하기위해서는 p=s로 초기화 할 필요가 있음 
	
	for(i=0;i<strlen(s);i++)
	{
		s[i]=tolower(s[i]); //소문자로 변환시키는 함수 
	}
	 
	printf("\n소문자로 변환한 결과: %s\n",s);
}
