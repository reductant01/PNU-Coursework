#include <stdio.h>
int main()
{
	int age;
	char gender;
	double height;
	 
//	printf("성별은? (남자 = M, 여자는= F)"); 문제발생 하지 않음 
//	scanf("%c", &gender);

	printf("나이는?");
	scanf("%d", &age);
	
	printf("키는?");
	scanf("%lf", &height);
	
	fflush(stdin); //키보드 버퍼의 내용을 비워줘야함! 
	
	printf("성별은? (남자 = M, 여자는= F)"); //키보드 버퍼에 저장된  enter키를 문자로 입력받음 (주의!) 
	scanf("%c", &gender);
	
	printf("성별 : %c\n", gender); 	
	printf("나이 : %d세\n", age); 
	printf("키 : %.1fcm\n", height); 		
	
	
}
