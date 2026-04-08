#include <stdio.h>
#define PI 3.141592
#define CIRCUM(r) (2*PI*(r))
#define AREA(r) (PI*(r)*(r))
#define DATE(Y, M, D) Y ## M ## D

int main()
{
	int radius;
	
	printf("원의 반지름 radius(cm)의 값은?");
	scanf("%d",&radius);
	
	printf("원의 둘레 %.2f(cm)이고 \n",CIRCUM(radius));
	printf("원의 넓이는 %.2f(cm)입니다\n",AREA(radius));
	printf("생년월일 : %d\n", DATE(11, 06, 10));
}
