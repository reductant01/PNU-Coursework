#include <stdio.h>

int main()
{

	char name[6]={'P','u','s','a','n','\0'};
	char str[6]="Seoul";
	char city[20];
	
	printf("도시? ");
	//scanf("%s",city); //scanf("%s",&city[0]) 안됨 
	gets(city);
	
	printf("%s\n",name);
	printf("%s\n",str+2); //str의 3번쨰부터 출력 
	printf("%c\n",str[2]); //printf("%s\n",str[2]);는 에러 발생
	
	//printf("%s\n",city); 
	puts(city);
}
