#include <stdio.h>

int main()
{
	int kor, mat, eng;
	int sum=0;  //누적할 변수는 초기화한다 
	double avg;
	
	char grade; //학점을 저장할 변수
	
	printf("국어점수를 입력하세요: "); 
	scanf("%d",&kor);
	
	printf("영어점수를 입력하세요: "); 
	scanf("%d",&eng);	
	
	printf("수학점수를 입력하세요: "); 
	scanf("%d",&mat);
	
	sum = kor + eng + mat;
	avg = sum/3.0; //(double)sum/3
	
	//등급을 구한다
	if(avg>=90)
		grade='A';
	else if(avg>=80)
		grade='B';	 
	else if(avg>=70)
		grade='C';	 
	else if(avg>=60)
		grade='D';	 
	else
		grade='F';	 	
		
	//결과를 출력한다
	printf("총점:%d\n",sum);
	printf("평균:%.1f\n",avg);
	printf("등급:%c\n",grade);
	
}
