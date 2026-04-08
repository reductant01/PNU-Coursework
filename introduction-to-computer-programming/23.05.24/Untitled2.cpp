#include <stdio.h>
#include <stdlib.h> //rand(), srand(), random()
#include <time.h>
#include <string.h>

void evalSrp(char [], char []);

char srp[][5]={"가위","바위","보"}; // 한글은 2바이트 차지 
char mySrp[5];
	

int main()
{
	int random;
	char retry;
	
	srand(time(NULL)); //난수의 씨드 함수 
	
	while(1)
	{
		printf("가위? 바위? 보? ");
		scanf("%s",mySrp);
		
		//컴퓨터의 가위바위보	
		random=rand()%3; //0~2사이의 난수 
		evalSrp(srp[random],mySrp);	
		
		fflush(stdin);
		
		printf("게속하시곘습니까(y/n) ");
		scanf("%c",&retry);
		
		if(retry=='y')
			continue;
		else
			break;	
		printf("프로그램 종료");
	}
	 
}
void evalSrp(char comp[], char me[])
{
	if(strcmp(me, "가위")==0)
	{
			if(strcmp(comp,"가위")==0)
			{
				printf("나:%s, 컴퓨터:%s\n",me,comp);
				printf("비겼습니다.\n\n"); 
			}
			else if(strcmp(comp,"바위")==0)
			{
				printf("나:%s, 컴퓨터:%s\n",me,comp);
				printf("내가 졌습니다.\n\n"); 
			}
			else
			{
				printf("나:%s, 컴퓨터:%s\n",me,comp);
				printf("내가 이겼습니다.\n\n"); 
			} 
	}
	else if(strcmp(me,"바위")==0)
	{
		if(strcmp(comp,"가위")==0)
			{
				printf("나:%s, 컴퓨터:%s\n",me,comp);
				printf("내가 이겼습니다.\n\n"); 
			}
			else if(strcmp(comp,"바위")==0)
			{
				printf("나:%s, 컴퓨터:%s\n",me,comp);
				printf("비겼습니다.\n\n"); 
			}
			else
			{
				printf("나:%s, 컴퓨터:%s\n",me,comp);
				printf("내가 졌습니다.\n\n"); 
			}
	}
	else if(strcmp(me,"보")==0)
	{
		if(strcmp(comp,"가위")==0)
			{
				printf("나:%s, 컴퓨터:%s\n",me,comp);
				printf("내가 이겼습니다.\n\n"); 
			}
			else if(strcmp(comp,"바위")==0)
			{
				printf("나:%s, 컴퓨터:%s\n",me,comp);
				printf("내가 졌습니다.\n\n"); 
			}
			else
			{
				printf("나:%s, 컴퓨터:%s\n",me,comp);
				printf("비겼습니다.\n\n"); 
			}
	} 
	else
	{
		printf("가위바위보 오류!");
		exit(0); //프로그램 강제 종료 
	}
	
}
