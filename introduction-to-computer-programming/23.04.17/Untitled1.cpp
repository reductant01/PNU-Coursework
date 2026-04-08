#include <stdio.h>
//#define STR(A, B) "A는 B의 맴버입니다"
#define STR(A, B) #A"는 " #B"의 맴버입니다"

int main()
{
	puts(STR(태양, 빅뱅));
	puts(STR(서현, 소녀시대));
	
} 
