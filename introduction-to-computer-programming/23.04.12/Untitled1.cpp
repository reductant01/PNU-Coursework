#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int main()
{
	int i, j;
	
	for(i=1;i<=100;i++)
	{
		for(j=1;j<=10;j++)
		{
			if(kbhit()) // 키보드 입력시 작동 
				goto end;
			printf("#");
		}
		printf("\n");
	}
	printf("\n프로그램을 종료합니다.\n");
	exit(0); //return0 와 같은것, 뒷문장을 실행하지 않고 종료 
	
 end:
	printf("\n키보드를 눌렸습니다.");
		
	return 0;	
}
