#include <stdio.h>

int main()
{
	int a[]={10,20,30,40,50};
	int *p=a; //배열 a의 시작주소를 대입 
	int i;
	
	printf("a=%X\n",a);
	printf("p=%X\n\n",p); 
	
	printf("*p++ =>%d\n",*p++); //p값 사용 후 주소 1증가 
	printf("*++p =>%d\n",*++p); //p주소 1증가 후 p값 사용 
	
	p++;
	
	printf("(*p)++ =>%d\n",(*p)++); //p값 사용 후 p값 1증가 
	printf("++*p =>%d\n",++*p); //p값 1증가 후 사용 

	//배열 a의 내용 출력 
	for(i=0;i<5;i++)
		printf("a[%d]=%d\n",i,a[i]); //a[3]의 값이 42가 되어있는것 확인 
		
	printf("\n"); 
	
	//포인터의 내용 출력 
	p=a; //p의 주소를 a[0]으로 다시 초기화 시켜줘야함 
	for(i=0;i<5;i++)
		printf("*(p+%d)=%d\n",i,*(p+i));	
	
	printf("\n"); 

	//포인터의 크기 
	printf("size(p)=>%d\n",sizeof(p)); //포인터의 크기 (반드시 8바이트) 
	printf("size(*p)=>%d\n",sizeof(*p)); //포인터 값의 크기	(값이 정수형이므로 정수형의 크기인 4바이트 출력) 
	
}
