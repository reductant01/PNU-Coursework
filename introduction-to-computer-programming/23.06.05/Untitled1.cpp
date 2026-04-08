#include <stdio.h>

int main()
{
	int a=100, b=200;
	int *p1, *p2;
	
	p1=&a; //p1=a는 오류발생 
	printf("p1=&a : a=%d,  p1=%d\n",a, p1);
	printf("p1=&a : a=%d, &p1=%d\n",a, &p1);
	printf("p1=&a : a=%d, *p1=%d\n",a, *p1);
	
	*p1=*p1+1; //(*p1)++와 같다 
	printf("(*p)++ 후 : a=>%d, *p1=%d\n",a,*p1);
	
	p2=p1;
	printf("p2=p1 후 : a=%d, *p1=%d, p2=%d\n", a,*p1,*p2);
	
	(*p2)++;
	printf("(*p2)++ 후 : a=%d, *p1=%d, p2=%d\n", a,*p1,*p2);
	
	printf("%a=%u, &b=%u, b=%d\n", &a,&b,b);
	printf("p1=%u, p1-1=%u, *(p1-3)=%d\n", p1,p1-1,*(p1-3)); //p1=6487564일떄 p1-1=6487563이 되는것이 아니라 6487560이 나온다. (4바이트의 크기이기 떄문!) 
	
}
