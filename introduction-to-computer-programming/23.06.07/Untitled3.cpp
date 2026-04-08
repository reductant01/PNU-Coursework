#include <stdio.h>

int main()
{
	char *str[4]={"korea", "japen", "china", "usa"};
	char **p=str; //이중포인터인거 확인 !!!
	
	int i,j;
	
	for(i=0;i<4;i++)
		printf("*p++=%s\n",*p++);
		
	p=str; //위에서 p의 주소가 바뀌었으므로 초기화 필요!	
		
	for(i=0;i<5;i++)
	{
		printf("\n");		
		for(j=0;j<5;j++)
			printf("*(*(p+%d)+%d)=%c\n",i,j,*(*(p+i)+j));
		printf("\n");	
	}	
		
	
}
