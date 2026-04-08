#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) //명령행 인수 
{
	int i, sum=0;
	
	for(i=1;i<=10;i++) //클릭시 디버깅해보는 것 (로직 오류가 뜬 경우 유용) (프로젝트 파일로 만들지 않으면 디버깅되지않음) 
		sum += i;
	
	printf("i=%d, sum=%d\n",i,sum);
		
	return 0;
}
