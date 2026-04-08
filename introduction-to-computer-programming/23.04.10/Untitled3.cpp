#include <stdio.h>
int main()
{
	char start, ch;
	
	for(start='z';start>='a';start--)
	{
		for(ch='a';ch<start;ch++)
			printf(" ");
			
		for(ch=start;ch<='z';ch++)
			printf("%c",ch);
			
		printf("\n");		
	}
}
