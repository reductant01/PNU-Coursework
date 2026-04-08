#include <stdio.h>
#include <stdlib.h> //rand(), srand(), random()
#include <time.h>
#include <string.h>

void evalSrp(int, int);

char srp[][5]={"가위","바위","보"}; // 한글은 2바이트 차지 
char mySrp[5];
int i=0, v=0, d=0, c=0;
	

int main()
{
	int random,nSrp;
	char retry;
	
	srand(time(NULL)); //난수의 씨드 함수 
	
	while(1)
	{
		printf("가위? 바위? 보? ");
		scanf("%s",mySrp);
		
		//가위(0),바위(1),보(2)로 숫자 변환
		if(strcmp(mySrp,"가위")==0)
			nSrp=0;	
		else if(strcmp(mySrp,"바위")==0)
			nSrp=1;	
		else if(strcmp(mySrp,"보")==0)
			nSrp=2;
		else 
		{
			printf("입력이 잘못된것 같습니다.\n\n");
			continue;				 
		}				 
		
		//컴퓨터의 가위바위보	
		random=rand()%3; //0~2사이의 난수 
		evalSrp(random,nSrp);
		i++;	
		
		fflush(stdin);
		
		printf("게속하시곘습니까(y/n) ");
		scanf("%c",&retry);
		
		if(retry=='y')
		{	
			printf("\n"); 
			continue;
		}
		else
			break;	
		printf("프로그램 종료\n");
	}
	printf("전:%d, 승:%d, 무:%d, 패:%d\n",i,v,c,d);

	if(v>d)
		printf("나의 최종승리!");
	else if(v<d)	
		printf("컴퓨터의 최종승리...");
	else 
		printf("둘이 똑같네요");
	 
}
void evalSrp(int comp, int me)
{
	if(comp==me)
	{
		printf("컴퓨터:%s, 나:%s\n",srp[comp], mySrp);
		printf("비겼습니다.\n\n");
		c++;
	}
	else if(me==(comp-2) || me ==(comp+1))
	{
		printf("컴퓨터:%s, 나:%s\n",srp[comp], mySrp);
		printf("내가 이겼습니다.\n\n");
		v++;
	}
	else
	{
		printf("컴퓨터:%s, 나:%s\n",srp[comp], mySrp);
		printf("내가 졌습니다.\n\n");
		d++;
	}
		
}
