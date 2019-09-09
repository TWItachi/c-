#include <stdio.h>

int main()
{
	int score;
	printf("Please input a score ");
	scanf("%d",&score);
	if(score<60)
	{
	    printf("E"); 
	}
	if((60<=score)&&score<75)
	{
	    printf("D");
	}
	if((75<=score)&&score<80)
	{
		printf("C");
	}
	if((80<=score)&&score<90)
	{
		printf("B");
	}
	if(90<score)
	{
		printf("A");
	}
}
